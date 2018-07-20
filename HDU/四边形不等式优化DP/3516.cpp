//四边形不等式优化，石子合并 
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
const int maxn=1005,inf=0x3f3f3f3f;
int dp[maxn][maxn],x[maxn],y[maxn],p[maxn][maxn];

int main () {
	int n,i,j,k,l;
	while (scanf("%d",&n)!=EOF) {
		memset(dp,0,sizeof(dp));
		for (i=1;i<=n;i++) {
			scanf("%d%d",&x[i],&y[i]);
			p[i][i]=i;
		}
		for (l=2;l<=n;l++) {
			for (i=1;i<=n-l+1;i++) {
				j=i+l-1;
				dp[i][j]=inf;
				for (k=p[i][j-1];k<=p[i+1][j];k++) {
					int cost=dp[i][k]+dp[k+1][j]+abs(x[k+1]-x[i])+abs(y[k]-y[j]);
					if (cost<dp[i][j]) {
						dp[i][j]=cost;
						p[i][j]=k;
					}
				}
			}
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}
