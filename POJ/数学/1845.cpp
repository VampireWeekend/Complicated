#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int mod=9901; 

int main() {
	ll a,b,sum=0,ans=0;
	int i;
	scanf("%lld%lld",&a,&b);
	ll m=sqrt(a);
	for (i=2;i<=m;i++) {
		if (a%i) sum+=i;
		sum%=mod;
	}
	ll max=a;
	while (b) {
		if (b%2) {
			ans+=sum;
			ans%=mod;
		}
		sum*=max;
		sum+=max;
		sum%=mod;
		max*=max;
		max%=mod;
		b/=2;
	}
	ans+=max+1;
	ans%=mod;
	printf("%d\n",ans);
	return 0;
}
