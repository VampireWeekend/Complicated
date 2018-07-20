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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L); 
int head[maxn]; 
int size[maxn],son[maxn],fa[maxn],dep[maxn],top[maxn],dfn[maxn];
ll a[maxn];
ll f[maxn];
bool visit[maxn];
int n,m,num;
char s[5];

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

int dfs(int now,int step) {
	visit[now]=1;son[now]=-1;size[now]=1;dep[now]=step;
	int i;
	for (i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			fa[to]=now;
			size[now]+=dfs(to,step+1);
			if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;
		}
	}
	return size[now];
}

void dfs2(int now,int gr) {
	top[now]=gr;
	dfn[now]=++num;
	visit[now]=1;
	if (son[now]==-1) return;
	dfs2(son[now],gr);
	int i;
	for (i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) dfs2(to,to);
	}
}

int lowbit(int x) {
	return x&(-x);
}

ll getsum(int k) {
	ll ans=0;
	for (int i=k;i>0;i-=lowbit(i)) 
		ans+=f[i];
	return ans;
}

void update(int k,ll val) {
	for (int i=k;i<=n;i+=lowbit(i)) 
		f[i]+=val;
}

void modify(int u,int v,ll val) {
	int x=top[u],y=top[v];
	while (x!=y) {
		if (dep[x]<dep[y]) swap(x,y),swap(u,v);
		update(dfn[x],val);
		update(dfn[u]+1,-val);
		u=fa[x];
		x=top[u];
	}
	if (dep[u]<dep[v]) swap(u,v);
	update(dfn[v],val);
	update(dfn[u]+1,-val);
}

int main() {
while (scanf("%d%d%d",&n,&m,&m)!=EOF) {
	int i,x,y;
	ll d;
	num=0;
	mem0(f);
	memset(head,-1,sizeof(head));
	for (i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	mem0(visit);
	dfs(1,0);
	num=0;
	mem0(visit);
	dfs2(1,1);
	for (i=1;i<=n;i++) {
		update(dfn[i],a[i]);
		update(dfn[i]+1,-a[i]);
	}
	for (i=1;i<=m;i++) {
		scanf("%s",s);
		if (s[0]=='Q') {
			scanf("%d",&x);
			ll ans=getsum(dfn[x]);
			printf("%lld\n",ans);
		} else {
			scanf("%d%d%lld",&x,&y,&d);
			if (s[0]=='D') d=-d;
			modify(x,y,d);
		}
	}
}
	return 0;
}

