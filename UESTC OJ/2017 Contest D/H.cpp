#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
ll a[4][maxn],dp[4][maxn][4];

int main() {
	int n,i,j;
	scanf("%d",&n);
	while (n!=0) {
		for (i=1;i<=3;i++) {
			for (j=1;j<=n;j++) {
				scanf("%lld",&a[i][j]);
			}
		}
		dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=0;
		for (j=2;j<=n;j++) {
			dp[1][j][0]=max(dp[1][j-1][0],dp[1][j-1][1]);
			dp[1][j][1]=dp[1][j-1][0]+a[1][j-1]*a[1][j];
			dp[1][j][2]=0;
		}
		for (i=2;i<=3;i++) {
			dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][2]);
			dp[i][1][2]=dp[i-1][1][0]+a[i-1][1]*a[i][1];
			dp[i][1][1]=0;
		}
		for (i=2;i<=2;i++) {
			for (j=2;j<=n;j++) {
				dp[i][j][0]=max(
				dp[]);
				
				dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]);
				dp[i][j][1]=max(dp[i-1][j][2],dp[i][j][1]);
				dp[i][j][1]+=dp[i][j-1][0]+a[i][j-1]*a[i][j];
				dp[i][j][2]=max(dp[i][j-1][1],dp[i][j-1][0]);
				dp[i][j][2]=max(dp[i][j-1][2],dp[i][j][2]);
				dp[i][j][2]+=dp[i-1][j][0]+a[i-1][j]*a[i][j];
		    }
		}
		for (i=1;i<=3;i++) {
			for (j=1;j<=n;j++) {
				printf("%lld ",dp[i][j][0]);
			}
			cout << '\n';
		}
		for (i=1;i<=3;i++) {
			for (j=1;j<=n;j++) {
				printf("%lld ",dp[i][j][1]);
			}
			cout << '\n';
		}
		ll ans=max(dp[3][n][0],dp[3][n][1]);
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
