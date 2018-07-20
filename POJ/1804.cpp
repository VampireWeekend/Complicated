//ÄæÐò¶Ô
#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn=500005;
struct nwa {
	int a,b;
};
nwa num[maxn];
int order[maxn];
ll f[maxn];
int n;
ll ans;

bool cmp(nwa x,nwa y) {
	return (x.a<y.a);
}

int lowbit(int a) {
	return (a&(-a));
}

ll getsum(int tt) {
	int t=tt;
	ll sum=0;
	while (t) {
		sum+=f[t];
		t-=lowbit(t);
	}
	return sum;
}

void update(int tt,ll c) {
	int t=tt;
	while (t<=n) {
		f[t]+=c;
		t+=lowbit(t);
	}
}

int main() {
	int i,t,p;
	scanf("%d",&n);
while (n!=0) {
	for (i=1;i<=n;i++) {
		scanf("%d",&num[i].a);
		num[i].b=i;
	}
	sort(num+1,num+n+1,cmp);
	for (i=1;i<=n;i++) {
		order[num[i].b]=i;
		f[i]=0;
	}
	ans=0;
	for (i=1;i<=n;i++) {
		update(order[i],1);
		ans+=(ll)((ll)i-getsum(order[i]));
	}
	printf("%lld\n",ans);
	scanf("%d",&n);
}
	return 0;
} 
