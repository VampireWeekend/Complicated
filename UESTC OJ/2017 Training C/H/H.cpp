#include <cstdio>
#include <iostream>
#include <string.h> 
using namespace std;
typedef long long ll;
const int maxn=1005;
ll dp[5][maxn][maxn];
ll a[maxn][maxn];

ll max(ll a,ll b) {
	if (a>b) return a; else return b;
}

int main() {
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof(dp));
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			scanf("%lld",&a[i][j]);
		}
	}
	dp[1][1][1]=a[1][1];
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			dp[1][i+1][j]=max(dp[1][i+1][j],dp[1][i][j]+a[i+1][j]);
			dp[1][i][j+1]=max(dp[1][i][j+1],dp[1][i][j]+a[i][j+1]);
		//	cout << dp[1][i][j] << endl;
		}
	}
	dp[2][1][m]=a[1][m];
	for (i=1;i<=n;i++) {
		for (j=m;j>=1;j--) {
			dp[2][i+1][j]=max(dp[2][i+1][j],dp[2][i][j]+a[i+1][j]);
			dp[2][i][j-1]=max(dp[2][i][j-1],dp[2][i][j]+a[i][j-1]);
		}
	}
	dp[3][n][1]=a[n][1];
	for (i=n;i>=1;i--) {
		for (j=1;j<=m;j++) {
			dp[3][i-1][j]=max(dp[3][i-1][j],dp[3][i][j]+a[i-1][j]);
			dp[3][i][j+1]=max(dp[3][i][j+1],dp[3][i][j]+a[i][j+1]);
		}
	}
	dp[4][n][m]=a[n][m];
	for (i=n;i>=1;i--) {
		for (j=m;j>=1;j--) {
			dp[4][i-1][j]=max(dp[4][i-1][j],dp[4][i][j]+a[i-1][j]);
			dp[4][i][j-1]=max(dp[4][i][j-1],dp[4][i][j]+a[i][j-1]);
		}
	}
	ll ans=0;
	for (i=2;i<=n-1;i++) {
		for (j=2;j<=m-1;j++) {
			ans=max(ans,dp[1][i-1][j]+dp[4][i+1][j]+dp[2][i][j+1]+dp[3][i][j-1]);
			ans=max(ans,dp[1][i][j-1]+dp[4][i][j+1]+dp[2][i-1][j]+dp[3][i+1][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
