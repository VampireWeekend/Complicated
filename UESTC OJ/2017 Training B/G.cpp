#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
const int maxn=100005;
int low[maxn],color[maxn],dfn[maxn];
int x[maxn],y[maxn],val[maxn],comed[maxn],god[maxn];
bool instack[maxn],inque[maxn];
vector<int> v[maxn];
vector<int> e1[maxn];
vector<int> e2[maxn];
stack<int> st;
int num,n,m,cnum;

int min(int a,int b) {
	if (a>b) return b; else return a;
}

int max(int a,int b) {
	if (a<b) return b; else return a;
}

void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	instack[now]=1;
	st.push(now);
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if (instack[to]) 
		    low[now]=min(low[now],dfn[to]); 
	}
	if (dfn[now]==low[now]) {
		instack[now]=0;
		color[now]=++cnum;
		val[cnum]++;
		while (st.top()!=now) {
			color[st.top()]=cnum;
			val[cnum]++;
			instack[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

void spfato(int s){
	int i;
    memset(inque,0,sizeof(inque));
    memset(comed,0,sizeof(comed));
	inque[s]=1;
	queue<int> q;
	q.push(s);
	comed[s]=val[s];
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;      
		for (i=0;i<e1[now].size();i++) {
			int to=e1[now][i];
			if (comed[now]+val[to]>comed[to]) {
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
				comed[to]=comed[now]+val[to];
			}
		}
	}
}

void spfafrom(int s){
	int i;
    memset(inque,0,sizeof(inque));
    memset(god,0,sizeof(god));
	inque[s]=1;
	queue<int> q;
	q.push(s);
	god[s]=val[s];
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;      
		for (i=0;i<e2[now].size();i++) {
			int to=e2[now][i];
			if (god[now]+val[to]>god[to]) {
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
				god[to]=god[now]+val[to];
			}
		}
	}
}

int main() {
	int i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].push_back(y[i]);
	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));
	memset(color,0,sizeof(color));
	memset(val,0,sizeof(val));
	num=cnum=0;
	for (i=1;i<=n;i++)
	    if (!color[i]) tarjan(i);
	num=0;
	for (i=1;i<=m;i++) 
		if (color[x[i]]!=color[y[i]]) 
			e1[color[x[i]]].push_back(color[y[i]]);
	spfato(color[1]);
	num=0;
	for (i=1;i<=m;i++) 
		if (color[x[i]]!=color[y[i]]) 
			e2[color[y[i]]].push_back(color[x[i]]);
	spfafrom(color[1]);
	int ans=1;
	for (i=1;i<=m;i++) 
		if (color[x[i]]!=color[y[i]]&&god[color[x[i]]]!=0&&comed[color[y[i]]]!=0) 
	    	ans=max(ans,comed[color[y[i]]]+god[color[x[i]]]-val[color[1]]);
	printf("%d",ans);
	return 0;
}
/*
8 9
1 5
1 2
4 5
2 7
7 8
8 2
2 5
4 3
3 6
 
ans=5
*/
