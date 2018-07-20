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
const int maxn=10005,maxk=60,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],x[maxn];

bool linear_basis_insert(ll p) {
	for (int i=maxk;i>=0;i--) {
		if ((p>>i)%2==1) {
			if (!x[i]) {
				x[i]=p;
				for (int j=i-1;j>=0;j--) 
					if (x[j]&&((x[i]>>j)%2==1)) x[i]^=x[j];
                for (int j=i+1;j<=maxk;j++) 
					if ((x[j]>>i)%2==1) x[j]^=x[i];
				return true;
			} else p=p^x[i];
		}
	}
	return p!=0;
}

int main() {
	int cas,cot=0;
	bool zero;
	scanf("%d",&cas);
	while (cas--) {
		mem0(x);
		zero=true;
		cot++;
		printf("Case #%d:\n",cot);
		int n,i,j,q,tot=0;
		ll p;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			zero=zero&linear_basis_insert(a[i]);
		}
		scanf("%d",&q);
		for (i=0;i<=maxk;i++) if (x[i]) tot++;
		for (i=1;i<=q;i++) {
			scanf("%lld",&p);
			ll ans=0;
			if (!zero) p--;
			j=0;
			while (p) {
				while (!x[j]&&j<=maxk) j++;
				if (j>maxk) {
					ans=-1;break;
				}
				if (p%2) ans^=x[j];
				j++;
				p=p>>1;
			}
			printf("%lld\n",ans);
		} 
	}
	return 0;
}
