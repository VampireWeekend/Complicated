#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxw=50005,maxn=105;
int dp[maxw];

int main() {
	int n,i,j,w,wi,p,c,k;
	scanf("%d%d",&n,&w);
	memset(dp,0,sizeof(dp));
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&wi,&p,&c);
		if (c*wi>w) {
			for (j=wi;j<=w;j++) {
				dp[j]=max(dp[j],dp[j-wi]+p);
			}
		} else {
			k=1;int sum=0;
			while (sum+k<c) {
				for (j=w;j>=k*wi;j--) {
					dp[j]=max(dp[j],dp[j-k*wi]+k*p);
				}
				sum+=k;
				k*=2;
			}
			k=c-sum;
			for (j=w;j>=k*wi;j--) {
				dp[j]=max(dp[j],dp[j-k*wi]+k*p);
			}
		}
	}
	cout << dp[w];
	return 0;
}
