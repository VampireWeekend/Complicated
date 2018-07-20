#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn],a[maxn][maxn],mark[maxn][maxn];

int main() {
	int n,m,i,j,x,y,ans=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++) {
	    	scanf("%d",&a[i][j]);
	    	dp[i][j]=a[i][j];
	    	mark[i][j]=0;
	    }
	mark[1][1]=1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (dp[i][j]>0&&mark[i][j]) {
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]+a[i][j+1]);
				dp[i+1][j+2]=max(dp[i+1][j+2],dp[i][j]+a[i+1][j+2]);
				dp[i+2][j+1]=max(dp[i+2][j+1],dp[i][j]+a[i+2][j+1]);
				mark[i+1][j]=mark[i][j+1]=mark[i+1][j+2]=mark[i+2][j+1]=1;
				ans=max(ans,dp[i][j]);
		    }
		//    cout << dp[i][j];
		}
	//	cout << '\n';
	}
	cout << ans << endl;
}
