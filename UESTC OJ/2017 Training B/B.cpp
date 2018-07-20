#include <cstdio>
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=50005;
int dist[maxn],a[maxn],visit[maxn],mark[maxn],b[maxn];
struct node {
	int id,dist;
	node (int id,int dist): id(id),dist(dist) {}
	bool operator <(const node &x)const {
		return dist>x.dist;
	}
};
priority_queue<node> q;
int num,pnum;

int min(int a,int b) {
	if (a<b) return a; else return b;
}

void dijkstra (int n,int m) {
	memset(visit,0,sizeof(visit));
	int i;
	while (!q.empty()) {
		int now=q.top().id;
		q.pop();
		visit[now]=1;
		for (i=0;i<n;i++) {
			int to=(now+b[i])%m;
			if (!visit[to]&&dist[now]+b[i]<dist[to]) {
				dist[to]=dist[now]+b[i];
				q.push(node(to,dist[to]));
			}
		}
	}
}

int main() {
	int n,i,j,x,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	m=a[1];
	pnum=0;
	memset(mark,0,sizeof(mark));
	memset(dist,0x3f,sizeof(dist));
	mark[0]=1;
	q.push(node(0,0));
	dist[0]=0;
	b[pnum++]=a[1];
	for (i=1;i<=n;i++) {
		if (!mark[a[i]%m]) {
			mark[a[i]%m]=1;
			b[pnum++]=a[i];
	    	dist[a[i]%m]=a[i];
	    	q.push(node(a[i]%m,a[i]));
		}
	}
	dijkstra(pnum,m);
	int t;
	scanf("%d",&t);
	for (i=1;i<=t;i++) {
		scanf("%d",&x);
		if (dist[x%m]<=x) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
/*
3
8 79 154
8
0 233 154 387 308 237 158 79

*/
