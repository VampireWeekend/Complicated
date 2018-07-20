#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=10005;
int dp[maxn];

int main() {
	int i,j,n,k,t,a,b;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof(dp));
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&t,&a,&b);
		if (t==1) {
			for (j=b;j<=k;j++) {
				dp[j]=max(dp[j],dp[j-b]+a);
			}
		} else {
			for (j=k;j>=b;j--) {
				dp[j]=max(dp[j],dp[j-b]+a);
			}
		}
	}
	cout << dp[k] << endl;
	return 0;
}
