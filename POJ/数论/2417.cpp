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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
map<ll,int> mp;

ll fastpower(ll base,ll index,ll mod) {
	ll ans,now;
	if (index<0) return 1;
	ans=1;
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		ans%=mod;
		now=now*now;
		now%=mod;
		k/=2;
	}
	return ans;
}

ll bsgs(ll a,ll b,ll p) {
	int i; 
	if (p%a==0) return -1;
//	if (p==1) return 0;
	ll m=ceil(sqrt(p));
	ll l=b;
	mp[l]=1;
	for (i=1;i<=m;i++) {
		l*=a;
		l%=p;
		mp[l]=i+1;
	}
	l=fastpower(a,m,p);ll r=l;
	for (i=1;i<=m;i++) {
		if (mp[r]) {
			ll ans=i*m-mp[r]+1;
			mp.clear();
			return ans;
		}
		r*=l;
		r%=p;
	}
	mp.clear();
	return -1;
}

int main() {
	ll p,b,n;
	while (scanf("%lld%lld%lld",&p,&b,&n)!=EOF) {
		ll ans=bsgs(b,n,p);
		if (ans==-1) printf("no solution\n"); else 
		    printf("%lld\n",ans);
	}
	return 0;
}
