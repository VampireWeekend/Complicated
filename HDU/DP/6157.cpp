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
int dp[maxn][maxn][maxn];
int sum[maxn];

int main() {
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF) {
		int i,j,k,x,c;
		for (i=0;i<=n;i++) 
			for (j=0;j<=n;j++) 
				for (k=0;k<=n;k++) 
				    dp[i][j][k]=-inf;
		dp[0][0][0]=0;
		scanf("%d",&x);
		sum[1]=0;
		for (i=2;i<=n;i++) {
			scanf("%d",&c);
			sum[i]=sum[i-1]+c;
		}
		for (i=1;i<=n;i++) {
			dp[i][0][0]=0;
			for (j=1;j<=min(i,m);j++) {
				for (k=0;k<=j;k++) 
				    dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k],dp[i-1][j-1][k]));
				for (k=1;k<=j;k++)
				    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+x-2*sum[i]);
				for (k=0;k<j;k++)
				    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k+1]+x+2*sum[i]);
			}
		}
		printf("%d\n",dp[n][m][0]);
	} 
	return 0;
}

