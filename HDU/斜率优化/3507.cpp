//–±¬ ”≈ªØ 
#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;
const int maxn=500005;
typedef long long ll;
ll a[maxn],sum[maxn],q[maxn],dp[maxn];

ll sqr(ll x) {
	return x*x;
}

ll returnx(ll j,ll k) {
	return 2*(sum[j]-sum[k]);
}

ll returny(ll j,ll k) {
	return dp[j]+sqr(sum[j])-dp[k]-sqr(sum[k]);
}

int main() {
	int n,m,i,j,h,t;
    scanf("%d%d",&n,&m);
	sum[0]=dp[0]=0;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	h=1;t=0;q[0]=0;
	for (i=1;i<=n;i++) {
		while (t+1<h&&sum[i]*returnx(q[t+1],q[t])>=returny(q[t+1],q[t]))			
		    t++;
		dp[i]=dp[q[t]]+sqr(sum[i]-sum[q[t]])+m;
		while (t+1<h&&(returny(q[h-1],q[h-2])*returnx(i,q[h-1])>=returny(i,q[h-1])*returnx(q[h-1],q[h-2]))) 
			h--;
		q[h]=i;
		h++;
	}
	cout << dp[n] << endl;
	return 0;
}
