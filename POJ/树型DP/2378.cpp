#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
const int maxn=10005;
using namespace std;
vector<int> v[maxn];
int a[maxn],visit[maxn],sum[maxn];
int n;

int dfs(int now) {
	visit[now]=1;
	int f;
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!visit[to]) {
			f=dfs(to);
			a[now]=max(a[now],f);
			sum[now]+=f;
		}
	}
	a[now]=max(a[now],n-sum[now]-1);
	return sum[now]+1;
}

int main() {
	int i,x,y;
	memset(visit,0,sizeof(visit));
	memset(sum,0,sizeof(sum));
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		v[y].push_back(x);
		v[x].push_back(y);
	}
	int u=dfs(1),cnt=0;
	for (i=1;i<=n;i++) {
		if (a[i]<=n/2) cnt++,printf("%d\n",i);
	}
	if (!cnt) printf("NONE");
	return 0;
}
