#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cmath>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1005,maxk=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db eps = 1e-5;
int head[maxn],t[maxn];
bool inq[maxn];
db a[maxn],d[maxn];
int num;

struct Edge {
	int from,to,pre;
	db d;
};
Edge e[maxk*2];

void addedge(int from,int to,db d) {
	e[num].from=from,e[num].to=to,e[num].pre=head[from],e[num].d=d;
	head[from]=num++;
}

bool spfa(int n,db mid) {
	queue<int> q;
	mem0(t); mem0(inq);
	for (int i=1;i<=n;i++) d[i]=1e9;
	inq[1] = 1; q.push(1); d[1] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = 0;
		for (int i = head[now]; i != -1; i = e[i].pre) {
			int to = e[i].to;
			if (d[now] + mid*e[i].d - a[now] < d[to]) {
				d[to] = d[now] + mid*e[i].d - a[now];
				if (!inq[to]) {
					inq[to] = 1; q.push(to); t[to]++;
					if (t[to] > n) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int n, m, i, j;
	db l, r, mid, ans;
	num = 0; memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%lf", &a[i]);
	int x, y;
	for (i = 1; i <= m; i++) {
		scanf("%d%d%lf", &x, &y, &r);
		addedge(x, y, r);
	}
	l = 0; r = 1e4;
	while (true) {
		mid = (l + r) / 2.0;
		if (spfa(n,mid)) l = mid; else r = mid;
		if (fabs(r - l) < eps) break;
	}
	printf("%.2lf\n", mid);
	return 0;
}
