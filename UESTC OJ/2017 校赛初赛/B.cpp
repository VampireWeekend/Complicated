#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int maxn=100005;
int a[maxn],visit[maxn];
long long dp[maxn][4];
vector<int> son[maxn];

void dfs(int now) {
	visit[now]=1;
	int size=son[now].end()-son[now].begin();
    dp[now][2]=0;
    dp[now][0]=0;
    dp[now][1]=0;
    dp[now][3]=0;
	for (int i=0;i<size;i++) {
		int node=son[now][i];
		if (!visit[node]) {
			dfs(node);
			if (a[node]<=a[now]) dp[now][2]+=(dp[node][1]+1)*dp[now][0];
			if (a[node]>=a[now]) dp[now][2]+=(dp[node][0]+1)*dp[now][1];
			if (a[node]==a[now]) dp[now][2]+=(dp[node][3]+1)*dp[now][3];
			if (a[node]==a[now]) dp[now][3]+=dp[node][3]+1;
			if (a[node]>=a[now]) dp[now][0]+=dp[node][0]+1;
			if (a[node]<=a[now]) dp[now][1]+=dp[node][1]+1;
			dp[now][2]+=dp[node][2];
		}
	}
	dp[now][2]+=dp[now][0]+dp[now][1]-dp[now][3];
}

int main () {
	int n,i,l,k;
	scanf("%d",&n);
    memset(visit,0,sizeof(visit));
    for (i=1;i<=n;i++) 
    	scanf("%d",&a[i]);
	for (i=1;i<n;i++) {
		scanf("%d %d",&l,&k);
		son[k].push_back(l);
		son[l].push_back(k);
	}
	dfs(1);
	long long ans=dp[1][2];
	cout << ans;
	return 0;
}
