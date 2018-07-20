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
const int maxn=1005,maxk=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int head[maxn],step[maxn],x[maxk],y[maxk],d[maxk];
int dist[maxn],current[maxn];
bool visit[maxn],mark[maxk*2];
int num; 

struct Edge {
	int from,to,flow,pre;
};
Edge edge[maxk*2];

void addedge(int from,int to,int flow) {
	edge[num]=(Edge){from,to,flow,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,0,head[to]};
	head[to]=num++;
}

bool bfs (int n) {
	queue<int> q;
	q.push(1);
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[to]==-1&&edge[i].flow>0) {
				dist[to]=dist[now]+1;
				q.push(to);
			}
		}
	}
	return dist[n]!=-1;
}

int dfs(int now,int flow,int n) {
	int f;
	if (now==n) return flow;
	for (int i=current[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		current[now]=i;
		if (dist[now]+1==dist[to]&&edge[i].flow>0&&
		(f=dfs(to,min(flow,edge[i].flow),n))) {
			edge[i].flow-=f;
			edge[i^1].flow+=f;
			return f;
		}
	}
	return 0;
}

int dinic(int n) {
	int sum=0,f;
	while (bfs(n)) {
		memcpy(current,head,sizeof(head));
		while (f=dfs(1,inf,n)) sum+=f;
	}
	return sum;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j;
		num=0;
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;i++) {
			scanf("%d%d%d",&x[i],&y[i],&d[i]);
			addedge(x[i],y[i],d[i]);
		}
		mem0(visit);
		queue<int> q;
		q.push(1);
		step[1]=0;visit[1]=1;
		while (!q.empty()) {
			int now=q.front();
			q.pop();
			for (i=head[now];i!=-1;i=edge[i].pre) {
				int to=edge[i].to;
				if (!visit[to]) {
					visit[to]=1;
					step[to]=step[now]+1;
					q.push(to);
				}
			}
		}
		mem0(mark);
		for (i=1;i<=n;i++) {
			for (j=head[i];j!=-1;j=edge[j].pre) {
				int to=edge[j].to,from=edge[j].from;
				if (step[to]==step[from]+1) 
					mark[j]=1;
			}
		}
		num=0;memset(head,-1,sizeof(head));
		for (i=0;i<2*m;i+=2) {
			if (mark[i]) addedge(x[i/2+1],y[i/2+1],d[i/2+1]);
			if (mark[i+1]) addedge(y[i/2+1],x[i/2+1],d[i/2+1]);
		}
		int ans=dinic(n);
		printf("%d\n",ans);
	}
	return 0;
}

