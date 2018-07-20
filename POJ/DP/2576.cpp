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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535898L;
ll a[105],dp[maxn];

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j;
		ll tot=0,ans,m;
		cnt++;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			tot+=a[i];
		}
		ans=0;
		mem0(dp);
		dp[0]=1;
		for (i=1;i<=n;i++) {
			for (j=tot/2;j>=a[i];j--) {
				if (j-a[i]>=0)
				if (dp[j-a[i]]!=0)
			    	dp[j]=dp[j]|(dp[j-a[i]]<<1);
			}
		}
		for (i=tot/2;i>=0;i--) {
			if ((dp[i]>>(n/2))%2) {
				ans=i;
				break;
			}
			if (n%2) 
			    if ((dp[i]>>(n/2+1))%2) {
			    	ans=i;
				    break;
			    }
		}
		printf("Case %d: %lld %lld\n",cnt,ans,tot-ans);
	}
	return 0;
}

