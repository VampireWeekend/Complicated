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
const int maxn = 100005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f, mod = 1e9 + 7;
const ld pi = acos(-1.0L);
int size[maxn], top[maxn], son[maxn], fa[maxn], dep[maxn], dfn[maxn];
int a[maxn], head[maxn];
bool visit[maxn];
int num;

struct Edge {
	int from, to, pre;
};
Edge edge[maxn * 2];

void addedge(int from, int to) {
	edge[num]= (Edge) { from, to, head[from] };
	head[from] = num++;
	edge[num] = (Edge) { to, from, head[to] };
	head[to] = num++;
}

int dfs(int now,int step) {
	visit[now]=1;son[now]=-1;dep[now]=step;size[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
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
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs2(to,to);
	}
}

struct Tree {
	int l, r, lc, rc;
	ll sum1, sum2;
};
Tree tree[4 * maxn];

void build(int now, int l, int r) {
	tree[now].l = l; tree[now].r = r;
	tree[now].sum1 = tree[now].sum2 = 0;
	if (l == r)
		return;
	else {
		num++;
		tree[now].lc = num;
		build(num, l, (l + r) / 2);
		num++;
		tree[now].rc = num;
		build(num, (l + r) / 2 + 1, r);
	}
}

void update(int now, int pos, ll val, int t) {
//	cout << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum2 << endl;
	if (tree[now].l == tree[now].r && tree[now].r ==pos) {
		if (t) tree[now].sum2 = ((tree[now].sum2 + val) % mod + mod) % mod;
		else tree[now].sum1 = ((tree[now].sum1 + val) % mod + mod) % mod;
	}
	else {
		if (pos <= (tree[now].l + tree[now].r) / 2)
			update(tree[now].lc, pos, val, t);
		if (pos>(tree[now].l + tree[now].r) / 2)
			update(tree[now].rc, pos, val, t);
		if (t) {
			tree[now].sum2 = tree[tree[now].lc].sum2 + tree[tree[now].rc].sum2;
			tree[now].sum2 %= mod;
		}
		else {
			tree[now].sum1 = tree[tree[now].lc].sum1 + tree[tree[now].rc].sum1;
			tree[now].sum1 %= mod;
		}
	}
//	cout << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum2 << endl;
}

ll findsum(int now, int l, int r, int t) {
	if (tree[now].l >= l&&tree[now].r <= r) {
		if (t) return tree[now].sum2; else return tree[now].sum1;
	}
	else {
		ll ans = 0;
		if (l <= (tree[now].l + tree[now].r) / 2)
			ans = findsum(tree[now].lc, l, r, t);
		if (r>(tree[now].l + tree[now].r) / 2)
			ans += findsum(tree[now].rc, l, r, t);
		ans %= mod;
		return ans;
	}
}

ll modify(int pos, ll val) {
	int x = top[pos];
	while (fa[x]) {
		ll q=findsum(0,dfn[top[x]],dfn[top[x]]+size[x]-1,0);
		update(0, dfn[fa[x]], ((2*q*val+val*val)%mod+mod)%mod, 1);
		x = top[fa[x]];
	}
	update(0, dfn[pos],(val+mod)%mod, 0);
}

ll findval(int u, int v) {
	int x = top[u], y = top[v];
	ll ans = 0, d;
	while (x != y) {
		if (dep[x] < dep[y]) {
			swap(x, y);
			swap(u, v);
		}
		ans += findsum(0, dfn[x], dfn[u], 1);
		ans %= mod;
		if (son[u]!=-1) {
			d = findsum(0, dfn[son[u]], dfn[son[u]] + size[son[u]] - 1, 0);
			ans += (d*d) % mod;
			ans %= mod;
		}
		d = findsum(0, dfn[x], dfn[x] + size[x]-1, 0);
		ans -= (d*d) % mod;
		ans = (ans + mod) % mod;
		u = fa[x]; x = top[u];
	}
	if (dep[u] < dep[v]) swap(u, v);
	ans += findsum(0, dfn[v], dfn[u],1); ans %= mod;
	if (son[u]!=-1) {
		d = findsum(0, dfn[son[u]], dfn[son[u]] + size[son[u]] - 1, 0);
		ans += (d*d) % mod;
		ans %= mod;
	}
	if (fa[v]) {
		d = tree[0].sum1-findsum(0,dfn[v],dfn[v]+size[v]-1,0);
		ans += (d*d) % mod;
		ans = (ans + mod) % mod;
	}
	return ans;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int i, j, x, y, t;
		ll ans, sum = 0;
		num = 0; memset(head, -1, sizeof(head));
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum = (sum + a[i]) % mod;
		}
		for (i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			addedge(x, y);
		}
		fa[1] = 0;
		mem0(visit); dfs(1, 0);
		num = 0;
		mem0(visit); dfs2(1, 1);
		num = 0;
		build(0, 1, n);
		for (i = 1; i <= n; i++) {
			modify(i, a[i]);
		}
		for (i = 1; i <= m; i++) {
			scanf("%d%d%d", &t, &x, &y);
			if (t == 1) {
				sum+=y-a[x];sum=(sum+mod)%mod;
				modify(x, y - a[x]);
				a[x] = y;	
			}
			else {
				ans = (sum*sum)%mod-findval(x, y);
				if (ans < 0) ans += mod;
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}

