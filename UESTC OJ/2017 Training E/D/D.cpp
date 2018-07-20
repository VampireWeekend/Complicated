#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const ll n=6;
ll a[20],b[20],c[20];
ll x,y;

ll ExEuclid(ll a,ll b,ll &x,ll &y) {
	if (b==0) {
		x=1;y=0;
		return a;
	}
	ll d=ExEuclid(b,a%b,x,y);
	ll temp=x;x=y;y=temp-a/b*y;
	return d;
}

int main() {
	ll sum=1,ans=0,k=0;
	int i;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		sum*=a[i];
	}
	for (i=1;i<=n;i++) {
		cin >> b[i];
		k=max(k,b[i]);
		c[i]=sum/a[i];
		ll d=ExEuclid(a[i],c[i],x,y);
		ans+=y*c[i]*b[i];
		ans%=sum;
	}
	ans=(ans+sum)%sum;
	while (ans<k) ans+=sum;
	cout << ans;
	return 0;
}
