#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=85;
struct Thang{
	ll v,w;
	db ratio;
};
Thang a[maxn];
ll sum[maxn];
db ratio[maxn];
ll ans,size,m;

bool cmp (Thang x,Thang y) {
	return x.ratio>y.ratio;
}

void dfs(int now,ll val,ll weight) { 
	ans=max(ans,val);
	if (now==m) return;
	if (val+ceil(a[now+1].ratio*weight)<=ans) return;
	if (val+sum[now+1]<=ans) return;
	if (a[now+1].w<=weight) 
		dfs(now+1,val+a[now+1].v,weight-a[now+1].w);
	dfs(now+1,val,weight);
}

int main() {
	int i,j,n;
	while (scanf("%d%lld",&n,&size)!=EOF) {
		ll b,c;
		m=0;
		for (i=1;i<=n;i++) {
			scanf("%lld%lld",&b,&c);
		//	b=i;c=i*i;
			if (b<=size) {
				a[++m].w=b;
				a[m].v=c;
				a[m].ratio=(db)a[m].v/(db)a[m].w;
			}
		}
		sort(a+1,a+m+1,cmp);
		sum[m+1]=0;
		for (i=m;i>=1;i--) {
			sum[i]=sum[i+1]+a[i].v;
		}
		ans=0;
		for (i=1;i<=m;i++) {
			if (sum[i]>ans) dfs(i,a[i].v,size-a[i].w);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
