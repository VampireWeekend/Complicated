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
const int maxn=100001,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int size[maxn],son[maxn],fa[maxn],top[maxn],dep[maxn],dfn[maxn];
int ans[maxn];
bool visit[maxn];
int num;
vector<int> v[maxn];

struct Mayer{
	int x,y,d;
};
Mayer a[maxn];

bool cmp(Mayer a,Mayer b) {
	return a.d<b.d;
}

struct query {
	int x,y,id;
};
query q[maxn];

bool cmp2(query a,query b) {
	return a.y<b.y;
}

void addedge(int from,int to) {
	v[from].push_back(to);
	v[to].push_back(from);
}

int dfs(int now,int step) {
	visit[now]=1;son[now]=-1;dep[now]=step;size[now]=1;
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!visit[to]) {
			fa[to]=now;
			size[now]+=dfs(to,step+1);
			if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;
		}
	}
	return size[now];
}

void dfs2(int now,int t) {
	visit[now]=1;top[now]=t;dfn[now]=++num;
	if (son[now]!=-1) dfs2(son[now],t);
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!visit[to]) 
			dfs2(to,to);
	}
}

struct Tree {
	int l,r,lc,rc,max;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
	tree[now].l=l;tree[now].r=r;
	if (l==r) {
		tree[now].max=-1;
	} else {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
	}
}

void update(int now,int pos,int val) {
//	cout << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << endl;
	if (tree[now].l==tree[now].r&&tree[now].l==pos) {
		tree[now].max=val;
	} else {
		if (pos<=(tree[now].l+tree[now].r)/2) 
			update(tree[now].lc,pos,val);
		if (pos>(tree[now].l+tree[now].r)/2) 
			update(tree[now].rc,pos,val);
		tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
	}
//	cout << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << endl;
}

int findmax(int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].max;
	} else {
		int ans=-inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
			ans=max(ans,findmax(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2) 
			ans=max(ans,findmax(tree[now].rc,l,r));
		return ans;
	}
}

int findval(int u) {
	int x=top[u],ans=-1;
	while (x!=1) {
		ans=max(ans,findmax(1,dfn[x]-1,dfn[u]-1));
		u=fa[x];x=top[u];
	}
	ans=max(ans,findmax(1,dfn[son[x]]-1,dfn[u]-1));
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,m;
		scanf("%d",&n);
		for (i=1;i<n;i++) {
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].d);
			addedge(a[i].x,a[i].y);
		}
		mem0(visit);
		dfs(1,0);
		mem0(visit);
		num=0;
		dfs2(1,1);
		sort(a+1,a+n,cmp);
		scanf("%d",&m);
		build(1,1,n-1);
		for (i=1;i<=m;i++) {
			scanf("%d%d",&q[i].x,&q[i].y);
			q[i].id=i;
		}
		sort(q+1,q+m+1,cmp2);
		j=1;
		for (i=1;i<=m;i++) {
			while (a[j].d<=q[i].y&&j<n) {
				update(1,max(dfn[a[j].x],dfn[a[j].y])-1,a[j].d);
				j++;
			}
			ans[q[i].id]=findval(q[i].x);
		}
		for (i=1;i<=m;i++) printf("%d\n",ans[i]);
		for (i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}

