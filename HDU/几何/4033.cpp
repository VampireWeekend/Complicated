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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535897932384626L;
ld a[maxn];

ld sqr(ld x) {
	return x*x;
}

ld cal(int i,int j,ld len) {
	return acos((sqr(a[i])+sqr(a[j])-sqr(len))/(2.0L*a[i]*a[j]));
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		int n,i;
		ld l=20000L,r=0L,mid;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			cin >> a[i];
			if (i!=1) r=max(r,a[i-1]+a[i]);
			if (i!=1) l=min(l,abs(a[i]-a[i-1]));
		}
		ld h,k,sum=0L;
		h=r=max(r,a[n]+a[1]);
		k=l=min(l,abs(a[n]-a[1]));
		while (abs(sum-2.0L*pi)>1e-7L) {
			sum=0L;
			mid=(l+r)/2.0L;
			for (i=1;i<n;i++) {
				sum+=cal(i,i+1,mid);
			}
			sum+=cal(1,n,mid);
			if (sum>2.0L*pi) r=mid; else l=mid;
		}
		cout << "Case " << cnt << ": ";
        cout << setiosflags(ios::fixed) << setprecision(3);
        int flag=0;
        for (i=1;i<n;i++) {
        	ld w=(sqr(a[i])+sqr(a[i+1])-sqr(mid))/(2.0L*a[i]*a[i+1]);
        	if (w>=1L||w<=(-1L)) flag=1;
        }
        ld w=(sqr(a[1])+sqr(a[n])-sqr(mid))/(2.0L*a[1]*a[n]);
        if (w>=1L||w<=(-1L)) flag=1;
		if (abs(k-mid)<1e-7||abs(mid-h)<1e-7||flag) 
		    cout << "impossible\n";
		    else cout << mid << endl;
	}
	return 0;
}

