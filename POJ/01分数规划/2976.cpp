#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db eps=1e-6;

struct Pack{
	db a,b,d;
};
Pack p[maxn];

bool cmp(Pack x,Pack y) {
	return x.d<y.d;
}

db Dinkelbach(int n,int k) {
	db ans=0,l;
while (true) {
		l=ans;
	int i; db s0,s1;
	for (i=1;i<=n;i++) {
		p[i].d=p[i].a-l*p[i].b;
	}
	sort(p+1,p+n+1,cmp);
	s0=s1=0;
	for (i=k+1;i<=n;i++) {
		s0+=p[i].a;s1+=p[i].b;
	}
	ans=s0/s1;
	if (fabs(l-ans)<eps) return ans;
}
}

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	while (n||k) {
		int i;
		ll s1,s0;
		s1=s0=0;
		for (i=1;i<=n;i++)
			scanf("%lf",&p[i].a);
		for (i=1;i<=n;i++) 
			scanf("%lf",&p[i].b);
		db ans=Dinkelbach(n,k);
		printf("%.0lf\n",ans*100.0);
		scanf("%d%d",&n,&k);
	}
	return 0;
}
