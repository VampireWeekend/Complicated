#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
const int maxn=100005,maxk=1000005;
const int inf=0x3f3f3f3f;
int du[maxn],distmax[maxn],distmin[maxn],visit[maxn],num,n,m,cnum;
int color[maxn*2],dfn[maxn],low[maxn],instack[maxn];
int x[maxk],y[maxk],b[maxk];
vector<int> v[maxn];
vector<int> d[maxn];
vector<int> v2[maxn];
stack<int> st;

int min(int a,int b) {
	if (a>b) return b; else return a;
}

int max(int a,int b) {
	if (a<b) return b; else return a;
}

void tarjan(int now,int n) {
	dfn[now]=low[now]=++num;
	int i;
	st.push(now);
	instack[now]=1;
	for (i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!dfn[to]) {
			tarjan(to,n);
			low[now]=min(low[now],low[to]);
		} else if (instack[to])
		    low[now]=min(low[now],dfn[to]);
	}
	if (low[now]==dfn[now]) {
		color[now+n]=++cnum;
		instack[now]=0;
		while (st.top()!=now) {
			color[st.top()+n]=cnum;
			instack[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

bool coloring(int n,int p) {
	int i;
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	num=0;cnum=0;
	for (i=1;i<=n;i++) 
	    if (!color[i+p]) tarjan(i,p);
	memset(du,0,sizeof(du));
}
//×î¶ÌÂ· 
bool solvemax(int n) {
	coloring(n,0);
	int i,j;    //y[i]-x[i]>=-b[i] 
	for (i=1;i<=m;i++) {
		if (color[x[i]]==color[y[i]]&&b[i]!=0) {
			return false;
		} else if (color[x[i]]!=color[y[i]]) {
			d[color[x[i]]].push_back(-b[i]);
			v2[color[x[i]]].push_back(color[y[i]]);
			du[color[y[i]]]++;
		}
	}
    memset(distmin,0x3f,sizeof(distmin));
    queue<int> q;
    int cnt=0;
    for (i=1;i<=cnum;i++)
        if (!du[i]) {
        	q.push(i);
        	distmin[i]=100;
        }
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        cnt++;
    	for (j=0;j<v2[now].size();j++) {
    		int to=v2[now][j];
    		distmin[to]=min(distmin[to],distmin[now]+d[now][j]);
    		du[to]--;
    		if (du[to]==0) 
    			q.push(to);
    	}
    }
    if (cnt<cnum) return false;
    for (i=1;i<=cnum;i++)
    	if (distmin[i]<0) return false;
    return true;
}

bool solvemin(int n) {
	coloring(n,n);
	int i,j;    //x[i]-y[i]>=b[i] 
	for (i=1;i<=m;i++) {
		if (color[x[i]+n]==color[y[i]+n]&&b[i]!=0) {
			return false;
		} else if (color[x[i]+n]!=color[y[i]+n]) {
			d[color[y[i]+n]].push_back(b[i]);
			v2[color[y[i]+n]].push_back(color[x[i]+n]);
			du[color[x[i]+n]]++;
		}
	}
    memset(distmax,-0x3f,sizeof(distmax));
    queue<int> q;
    int cnt=0;
    for (i=1;i<=cnum;i++)
        if (!du[i]) {
        	q.push(i);
        	distmax[i]=0;
        }
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        cnt++;
    	for (j=0;j<v2[now].size();j++) {
    		int to=v2[now][j];
    		distmax[to]=max(distmax[to],distmax[now]+d[now][j]);
    		du[to]--;
    		if (du[to]==0) 
    		    q.push(to);
    	}
    }
    if (cnt<cnum) return false;
    for (i=1;i<=n;i++)
    	if (distmax[color[i+n]]>distmin[color[i]]) return false;
    return true;
}

int main() {
	int i;
    scanf("%d%d",&n,&m);
   	memset(color,0,sizeof(color));
 /* 	n=12;
   	m=n/2*3-1;
   	for (i=1;i<=n/2;i++) {
   		x[2*i-1]=2*i;y[2*i-1]=2*i-1;
   		x[2*i]=2*i-1;y[2*i]=2*i;
   		b[2*i-1]=b[2*i]=0;
   		if (i!=n/2) {
   			x[n+i]=i*2-1;y[n+i]=i*2+1;b[n+i]=20;
   		}
   	}*/
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x[i],&y[i],&b[i]);
		v[x[i]].push_back(y[i]);
	}
	int flag1=solvemax(n);
	for (i=1;i<=n;i++) {
		v[i].clear();
		v2[i].clear();
		d[i].clear();
	}
	for (i=1;i<=m;i++) {
		v[y[i]].push_back(x[i]);
	}
	int flag2=solvemin(n);
	if (!flag1||!flag2) {
		printf("-1");
	} else {
		for (i=1;i<=n;i++)
         	printf("%d %d\n",distmax[color[i+n]],distmin[color[i]]);
	}
	return 0;
}
/*
6 5
1 2 20
2 3 20
3 4 20
4 5 20
5 6 20
*/
