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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

ll a[maxn],sum[maxn];

int main() {
	int i,j,n;
	ll ans;
	scanf("%d",&n);
	sum[0]=0;
	for (i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	ans=abs(sum[n]-2*a[1]);
	for (i=2;i<n;i++) {
		ans=min(ans,abs(sum[n]-2*sum[i]));
	}
	printf("%lld\n",ans);
	return 0;
}
