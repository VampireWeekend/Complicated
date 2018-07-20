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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll sum[maxn],dp[maxn],q[maxn],pos[maxn]; 

ll returnx(ll j,ll k) {
	return j-k;
}

ll returny(ll j,ll k) {
	return sum[j]-sum[k];
}

int main() {
		int n,i,j,l,h,t;
		ll x;
		scanf("%d%d",&n,&l);
		getchar();
		sum[0]=dp[0]=0;pos[0]=-1;
		for (i=1;i<=n;i++) {
			scanf("%lld",&x);
			sum[i]=sum[i-1]+x;
		}
		h=1;t=0;q[0]=0;
		mem0(q);
		ll ans=0;
		for (i=l;i<=n;i++) {
			while (t+1<h&&(sum[i]-sum[q[t+1]])*(i-q[t])>=(sum[i]-sum[q[t]])*(i-q[t+1]))
			    t++;
			dp[i]=sum[i]-sum[q[t]];
			pos[i]=q[t];
			if (dp[i]*(ans-pos[ans])>dp[ans]*(i-pos[i])) ans=i;
			while (t+1<h&&(returny(q[h-1],q[h-2])*returnx(i-l+1,q[h-1])>=returny(i-l+1,q[h-1])*returnx(q[h-1],q[h-2]))) 
				h--;
			q[h]=i-l+1;
			h++;
		}
		printf("%lld\n",1000*dp[ans]/(ans-pos[ans]));
	return 0;
}

