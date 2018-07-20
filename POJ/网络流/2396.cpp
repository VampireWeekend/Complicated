#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=255,maxk=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],current[maxn],dist[maxn],f[maxn];
int up[maxk],down[maxk];
int cnt[maxn][25];
bool visit[maxn];
int num;

struct Edge {
	int from,to,pre,flow;
};
Edge edge[maxk*2];

void addedge(int from,int to,int flow) {
	edge[num]=(Edge){from,to,head[from],flow};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],0};
	head[to]=num++;
}

bool bfs(int n) {
	meminf(dist);
	mem0(visit);
	queue<int> q;
	q.push(0);
	dist[0]=0;visit[0]=1;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (!visit[to]&&edge[i].flow>0) q.push(to),dist[to]=dist[now]+1,visit[to]=1;
		}
	}
	return dist[n]!=inf;
}

int dfs(int now,int flow,int t) {
	if (now==t) return flow;
	for (int i=current[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to,f;
		current[now]=i;
		if (dist[to]==dist[now]+1&&edge[i].flow>0&&(f=dfs(to,min(flow,edge[i].flow),t))) {
			edge[i].flow-=f;
			edge[i^1].flow+=f;
			return f;
		}
	}
	return 0;
}

int dinic(int n) {
	int ans=0,f;
	while (bfs(n)) {
		memcpy(current,head,sizeof(current));
		while (f=dfs(0,inf,n)) ans+=f;
	}
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j,k,q,x,y,d,l=0;
		char c;
		scanf("%d%d",&n,&m);
		num=0;memset(head,-1,sizeof(head));
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				cnt[i][j]=l++;
			}
		}
		mem0(f);
		for (i=1;i<=n;i++) {
			scanf("%d",&x);
	//		addedge(n+m+1,i,0);
			f[i]+=x;
			f[n+m+1]-=x;
		}
		for (i=1;i<=m;i++) {
			scanf("%d",&x);
	//		addedge(i+n,n+m+2,0);
			f[i+n]-=x;
			f[m+n+2]+=x;
		}
		scanf("%d",&q);
		mem0(down);meminf(up);
		for (k=1;k<=q;k++) {
			scanf("%d %d %c %d",&x,&y,&c,&d);
			if (c=='>') d++;
			if (c=='<') d--;
			int lr,rr,lc,rc;
			if (x==0) lr=1,rr=n; else lr=rr=x;
			if (y==0) lc=1,rc=m; else lc=rc=y;
			for (i=lr;i<=rr;i++) {
				for (j=lc;j<=rc;j++) {
					if (c!='>') up[cnt[i][j]]=min(up[cnt[i][j]],d);
					if (c!='<') down[cnt[i][j]]=max(down[cnt[i][j]],d);
				}
			}
		}
		if (f[n+m+1]+f[n+m+2]!=0) {
			printf("IMPOSSIBLE\n\n");
			continue;
		}
		int flag=0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (up[cnt[i][j]]<down[cnt[i][j]]) flag=1; else
				    addedge(i,j+n,up[cnt[i][j]]-down[cnt[i][j]]);
				f[j+n]+=down[cnt[i][j]];
				f[i]-=down[cnt[i][j]];
			}
		}
		if (flag) {
			printf("IMPOSSIBLE\n\n");
			continue;
		}
		for (i=1;i<=n+m+2;i++) {
			if (f[i]>0) addedge(0,i,f[i]); 
			    else addedge(i,n+m+3,-f[i]);
		}
		addedge(n+m+2,n+m+1,inf);
	/*	for (i=0;i<num;i+=2) {
			cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].flow << endl;
		}*/
		int s=0;
		for (i=head[0];i!=-1;i=edge[i].pre) {
			s+=edge[i].flow;
		}
		int ans=dinic(n+m+3);
		if (ans!=s) {
			printf("IMPOSSIBLE\n\n");
			continue;
		}
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				printf("%d ",edge[cnt[i][j]*2+1].flow+down[cnt[i][j]]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

