#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn=105;
const int inf=0x3f3f3f3f;
vector<int> v[maxn];
vector<int> d[maxn];
int dist[maxn],pre[maxn],sum[maxn],num[maxn],inque[maxn];

void spfa(int s,int t) {
	int i;
	for (i=1;i<=t;i++) {
		sum[i]=0;
		dist[i]=inf;
		inque[i]=0;
	}
	dist[1]=0;
	inque[1]=1; 
	sum[1]=num[1];
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (i=0;i<v[now].size();i++) {
			int to=v[now][i];
			if (dist[now]+d[now][i]<=dist[to]) {
				if (dist[to]==dist[now]+d[now][i])
				    sum[to]=max(sum[to],sum[now]+num[to]);
				else
				    sum[to]=sum[now]+num[to];
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
				dist[to]=dist[now]+d[now][i];
			}
		}
	}
	if (dist[t]==inf) printf("impossible"); else 
	    printf("%d %d\n",dist[t],sum[t]);
}

int main() {
	int n,i,m,x,y,s;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&num[i]);
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&s);
		v[x].push_back(y);
		v[y].push_back(x);
		d[x].push_back(s);
		d[y].push_back(s);
	}
	spfa(1,n);
	return 0;
}

/*
6
1 1 2 3 1 0
7
1 2 2
2 3 3
3 6 4
1 4 4
4 3 2
4 5 3
5 6 2
*/
