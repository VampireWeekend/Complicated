#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn=505;
ll dp[maxn][maxn],dp2[maxn][maxn];
ll a[maxn];

int main() {
	ll mod;
	int n,m,b,i,j,k,l;
	scanf("%d%d%d%lld",&n,&m,&b,&mod);
	a[0]=0;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	memset(dp,0,sizeof(dp));
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++) {
		for (j=0;j<a[i];j++) dp[i][j]=dp[i-1][j];
		for (j=a[i];j<=b;j++) {
			dp[i][j]=dp[i-1][j]+1;
//			cout << "1 " << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	}
	for (i=2;i<=m;i++) {
		if (i%2==0) {
		for (k=a[j];k<=b;k++) dp2[0][k]=0;
		for (j=1;j<=n;j++) {
			for (k=0;k<a[j];k++) dp2[j][k]=dp2[j-1][k];
			for (k=a[j];k<=b;k++) {
				dp2[j][k]=dp2[j-1][k]+dp[j][k-a[j]];
				dp2[j][k]%=mod;
	//			cout << i << ' ' << j << ' ' << k << ' ' << dp2[j][k] << endl;
			}
	    }
		}
		else {
		for (k=a[j];k<=b;k++) dp[0][k]=0;
		for (j=1;j<=n;j++) {
			for (k=0;k<a[j];k++) dp[j][k]=dp[j-1][k];
		    for (k=a[j];k<=b;k++) {
				dp[j][k]=dp[j-1][k]+dp2[j][k-a[j]];
				dp[j][k]%=mod;
	//		cout << i << ' ' << j << ' ' << k << ' ' << dp[j][k] << endl;
		    }
	    }
		}
	}
	if (m%2==0) printf("%lld\n",dp2[n][b]); else printf("%lld\n",dp[n][b]);
	return 0;
}
/*
3 3 1 
2147483611
0 0 1
*/
