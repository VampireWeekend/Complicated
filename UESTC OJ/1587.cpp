#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod=554056561;

int main() {
	int n,i;
	ll ans,pre1,pre2,now1,now2;
	scanf("%d",&n);
	if (n<=2) {
		if (n==1) cout << 3;
		if (n==2) cout << 9;
		return 0;
	}
	pre1=3;pre2=6;
	for (i=3;i<=n;i++) {
		now1=pre1+pre2;
		now2=pre1*2+pre2;
		pre2=now2%mod;
		pre1=now1%mod;
	}
	ans=(pre1+pre2)%mod;
	cout << ans << endl;
	return 0; 
} 
