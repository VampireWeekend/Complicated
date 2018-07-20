//ÄæÐò¶Ô
#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn=100005;
struct JCole {
	int a,b;
};
JCole x[maxn],y[maxn];
int order[maxn];
ll f[maxn];
int n;
ll ans;

bool cmp(JCole q,JCole w) {
	return q.a<w.a;
}

ll lowbit(ll a) {
	return (a&(-a));
}

ll getsum(int tt) {
	ll sum=0;
	int t=tt;
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
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&x[i].a);
		x[i].b=i;
	}
	sort(x+1,x+n+1,cmp);
	for (i=1;i<=n;i++) {
		scanf("%d",&y[i].a);
		y[i].b=i;
	}
	sort(y+1,y+n+1,cmp);
	for (i=1;i<=n;i++) {
		order[x[i].b]=y[i].b;
		f[i]=0;
	}
	ans=0;
	for (i=1;i<=n;i++) {
		update(order[i],1);
		ans+=(ll)((ll)i-getsum(order[i]));
	}
	printf("%lld",ans);
	return 0;
} 
