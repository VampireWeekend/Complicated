#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll dp[maxn][maxn],a[maxn][maxn],c[maxn][maxn];
char s[maxn];

int main() {
	int n,i,j,k;
	c[0][0]=1;
	for (i=1;i<=100;i++) {
		c[i][0]=c[i][i]=1;
		for (j=1;j<i;j++) {
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	while (scanf("%d",&n)!=EOF) {
		mem0(dp);mem0(a);
		for (i=1;i<=n;i++) {
			scanf("%lld",&dp[i][i]);
			a[i][i]=1;
		}
		scanf("%s",s+1);
		for (i=1;i<n;i++) {
			for (j=1;j+i<=n;j++) {
				for (k=j;k<j+i;k++) {
					if (s[k]=='+') {
						dp[j][j+i]+=((dp[j][k]*a[k+1][j+i]+dp[k+1][j+i]*a[j][k])%mod)*c[i-1][k-j];
						dp[j][j+i]%=mod;
					}
					else if (s[k]=='-') {
						dp[j][j+i]+=((dp[j][k]*a[k+1][j+i]-dp[k+1][j+i]*a[j][k])%mod)*c[i-1][k-j];
						dp[j][j+i]%=mod;
					} else {
						dp[j][j+i]+=((dp[j][k]*dp[k+1][j+i])%mod)*c[i-1][k-j];
						dp[j][j+i]%=mod;
					}
					a[j][j+i]+=(c[i-1][k-j]*a[j][k]%mod)*a[k+1][j+i]%mod;
					a[j][j+i]%=mod;
				}
	//			cout << j << ' ' << j+i << ' ' << dp[j][j+i] << ' ' << a[j][j+i] << endl;
			}
		}
		while (dp[1][n]<0) dp[1][n]+=mod;
		printf("%lld\n",dp[1][n]);
	}
	return 0;
}

