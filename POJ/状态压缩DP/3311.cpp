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
const int maxn=15,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn][maxn],dp[1036][maxn];

int main() {
	int n;
	scanf("%d",&n);
	while (n) {
		int i,j,k;
		for (i=0;i<=n;i++) {
			for (j=0;j<=n;j++) {
				scanf("%lld",&a[i][j]);
			}
		}
		for (k=0;k<=n;k++) {
			for (i=0;i<=n;i++) {
				if (i==k) continue;
				for (j=0;j<=n;j++) {
					if (j==k||j==i) continue;
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		meminf(dp);
		for (i=0;i<=n;i++) dp[0][i]=0;
		for (k=1;k<=(1<<n);k++) {
			for (i=1;i<=n;i++) {
				if (k&(1<<(i-1))) {          //当前状态经过i 
					if (k==(1<<(i-1))) 
					    dp[k][i]=a[0][i];    //当前状态只经过i 
					else {   
						for (j=1;j<=n;j++) { //当前状态经过多个城市，枚举中间点j 
							if (j==i) continue;
							if (k&(1<<(j-1))) 
							    dp[k][i]=min(dp[k^(1<<(i-1))][j]+a[j][i],dp[k][i]);
						}
					}
				} 
			} 
		}
		ll ans=inf;
		for (i=1;i<=n;i++) {
			ans=min(ans,dp[(1<<n)-1][i]+a[i][0]); //经过所有城市，再从i回到0 
		}
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}

