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
typedef double db;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll dp[maxn][maxn],a[maxn];

int main() {
	int n,i,j,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	meminf(dp);
	for (i=2;i<n;i++) dp[i][i]=a[i-1]*a[i]*a[i+1]; 
	for (i=1;i<=n-2;i++) {
		for (j=2;j+i<n;j++) {
			dp[j][j+i]=min(dp[j][j+i],dp[j+1][j+i]+a[j]*a[j-1]*a[j+i+1]);
			dp[j][j+i]=min(dp[j][j+i],dp[j][j+i-1]+a[j+i]*a[j-1]*a[j+i+1]);
			for (k=j+1;k<j+i;k++) {
				dp[j][j+i]=min(dp[j][j+i],dp[j][k-1]+dp[k+1][j+i]+a[k]*a[j-1]*a[j+i+1]);
			}
	//		cout << j << ' ' << j+i << ' ' << dp[j][j+i] << endl;
		}
	}
	printf("%lld\n",dp[2][n-1]);
	return 0;
}

