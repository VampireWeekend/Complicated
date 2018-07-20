#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=15,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ll b[maxn],num[maxn];

int main() {
	int cas,i,j;
	scanf("%d",&cas);
	b[0]=1;
	for (i=1;i<=10;i++) b[i]=b[i-1]*i;
	while (cas--) {
		ll n,m=0,k;
		scanf("%lld",&n);
		ld ans=0L;
		int len=0;
		k=n;
		while (k) {
			num[++len]=k%10;
			k/=10;
		}
		for (j=len;j>1;j--) {
			for (i=1;i<len;i++) {
		    	if (num[i]>num[j]) m+=b[j-1];
	    	}
		}
		n=b[len];
		ll o=1;
		o=max(o,m-100000);
		ld h=1.0L/(ld)n;
		if (m!=0) ans=h;
		for (j=m-1;j>=o;j--) {
			h=h*(ld)(j)/(ld)(n); 
			ans+=h;
	//		if (fabs(h)<1e-40) break;
		}
		cout << setiosflags(ios::fixed) << setprecision(9);
		cout << ans << endl;
	}
	return 0;
}

