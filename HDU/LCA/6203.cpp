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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 10001
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=10005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],dep[maxn],in[2*maxn],out[2*maxn],a[maxn*2],d[maxn*2];
int mn[maxn*2][20],f[maxn*2],from[maxn*5],to[maxn*5],lca[maxn*5];
bool visit[maxn];
int num,dfn;

struct node{
	int id,dep;
	node(int id,int dep): id(id),dep(dep) {}
	bool operator<(const node &x) const {
		return dep<x.dep;
	}
};

int lowbit(int a) {
	return (a&(-a));
}

int getsum(int tt) {
	int sum=0;
	for (int t=tt;t;t-=lowbit(t)) 
		sum+=f[t];
	return sum;
}

void update(int tt,ll c,int n) {
	int t=tt;
	for (int t=tt;t<=n;t+=lowbit(t))
		f[t]+=c;
}

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void dfs(int now,int step) {
	visit[now]=1;
	a[++dfn]=now;d[dfn]=step;
	in[now]=out[now]=dfn;dep[now]=step;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,step+1);
			out[now]=++dfn;
			a[dfn]=now;d[dfn]=step;
		}
	}
}

void init(int n) {
	int i,j;
	for (i=1;i<=n;i++) mn[i][0]=i;
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			int p=mn[i][j-1],q=mn[i+(1<<(j-1))][j-1];
			mn[i][j]=d[p]<d[q]?p:q;
		}
	}
}

int findlca(int l,int r) {
	int k=0;
	if (l>r) swap(l,r);
	while (1<<(k+1)<=(r-l+1)) k++;
	int p=mn[l][k],q=mn[r-(1<<k)+1][k];
	return d[p]<d[q]?a[p]:a[q];
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		int i,j,x,y,p;
		num=dfn=0;
		n++;
		memset(head,-1,sizeof(head));
		for (i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			addedge(x+1,y+1);
		}
		scanf("%d",&p);
		mem0(visit);
		dfs(1,1);
		init(2*n-1);
		priority_queue<node> pq;
		for (i=1;i<=p;i++) {
			scanf("%d%d",&from[i],&to[i]);
			from[i]++;to[i]++;
			lca[i]=findlca(in[from[i]],in[to[i]]);
			pq.push(node(i,dep[lca[i]]));
		}
		mem0(f);
		int ans=0;
		for (i=1;i<=p;i++) {
			int now=pq.top().id;
			pq.pop();
			if (getsum(in[from[now]])>0||getsum(in[to[now]])>0) continue; else {
				ans++;
				update(in[lca[now]],1,2*n);
				update(out[lca[now]]+1,-1,2*n);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
