#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=155,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db a[maxn][maxn]; 
db dp[maxn][10];

int main() {
	int m;
	scanf("%d",&m);
	while (m!=-1) {
		int i,j,k,l,n;
		n=(1<<m);
		mem0(dp);
		for (i=1;i<=n;i++) {
			dp[i][0]=1.0;
			for (j=1;j<=n;j++) {
				scanf("%lf",&a[i][j]);
			}
		}
		for (i=1;i<=m;i++) {
			int p=(1<<i);
			for (j=1;j<=n;j+=p) {
				for (k=j;k<j+p/2;k++) {
					for (l=j+p/2;l<j+p;l++) {
						dp[k][i]+=dp[l][i-1]*a[k][l];
					}
					dp[k][i]*=dp[k][i-1];
				}
				for (k=j+p/2;k<j+p;k++) {
					for (l=j;l<j+p/2;l++) {
						dp[k][i]+=dp[l][i-1]*a[k][l];
					}
					dp[k][i]*=dp[k][i-1];
				}
			}
	/*		for (j=1;j<=n;j++) {
				printf("%lf ",dp[j][i]);
			}
			printf("\n");*/
		}
		int ans=1;
		for (i=2;i<=n;i++) {
			if (dp[i][m]>dp[ans][m]) ans=i;
		}
		printf("%d\n",ans);
		scanf("%d",&m);
	}
	return 0;
}
