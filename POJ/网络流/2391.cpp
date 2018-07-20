#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=505,maxk=200005;
const int inf=0x3f3f3f3f;
const ll llinf=1e16;
int current[maxn],dist[maxn],num,c[maxn],b[maxn],head[maxn];
ll a[maxn][maxn];

struct Edge {
	int from,to,flow,pre;
}; 
vector<Edge> edge;

void addedge(int s,int t,int flow) {
	Edge e;
	e.from=s;
	e.to=t;
	e.flow=flow;
	e.pre=head[s];
	edge.push_back(e);
	head[s]=num;
	num++;
	e.from=t;
	e.to=s;
	e.flow=0;
	e.pre=head[t];
	edge.push_back(e);
	head[t]=num;
	num++;
}

int bfs(int n) {
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	dist[0]=0;
	q.push(0);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int k=i,to=edge[i].to;
			if (dist[to]==-1&&edge[k].flow>0) {
				dist[to]=dist[now]+1;
				q.push(to);
			}
		}
	}
	if (dist[n]==-1) return 0; else return dist[n];
}

int dfs(int now,int flow,int t) {
	if (now==t) return flow;
	int f;
	for (int i=current[now];i!=-1;i=edge[i].pre) {
		int k=i,to=edge[i].to;
		current[now]=i;
		if (edge[k].flow>0&&dist[to]==dist[now]+1&&(f=dfs(to,min(flow,edge[k].flow),t))) {
			edge[k].flow-=f;
			edge[k^1].flow+=f;
			return f;
		}
	}
	return 0;
}

int dinic(int t) {
	int f,sum=0;
	while (bfs(t)) {
		for (int i=0;i<=t;i++) current[i]=head[i];
		while (f=dfs(0,inf,t)) sum+=f;
	}
	return sum;
}

void buildgraph(ll mid,int n) {
	int i,j;
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<=n;i++) {
		addedge(0,i,c[i]);
		addedge(i+n,2*n+1,b[i]);
	    addedge(i,i+n,inf);
	    for (j=i+1;j<=n;j++) 
		    if (a[i][j]<=mid) {
		    	addedge(i,j+n,inf);
		    	addedge(j,i+n,inf);
		    }
	}
}

ll solve(int n,ll limit,int sum) {
	ll l=0,r=limit,mid;
	int i;
	ll ans=-1;
	while (l<=r) {
		mid=(l+r)/2;
		buildgraph(mid,n);
		if (dinic(2*n+1)>=sum) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
		edge.clear();
	}
	return ans;
}

int main() {
	int f,p,i,j,n,k,sum,x,y;
	ll d;
	scanf("%d%d",&n,&p);
	sum=0;
	for (i=1;i<=n;i++) {
		scanf("%d%d",&c[i],&b[i]);
		sum+=c[i];
	}
	ll maxd=0;
	memset(a,0x3f,sizeof(a));
	for (i=1;i<=p;i++) {
		scanf("%d%d%lld",&x,&y,&d);
		if (a[x][y]>d) a[x][y]=d;
		if (a[y][x]>d) a[y][x]=d;
	}
	for (i=1;i<=n;i++) 
		for (j=1;j<=n;j++) 
			for (k=1;k<=n;k++) 
				if (a[j][i]+a[i][k]<a[j][k]) a[j][k]=a[j][i]+a[i][k];
	ll ans=solve(n,llinf,sum);
	printf("%lld\n",ans);
	return 0;
}
