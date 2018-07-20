//ºÙ÷¶ 
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
	ll v,w,num;
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
	int i;
	ans=max(ans,val);
	if (now==m+1) return;
	if (val+(ll)ceil(a[now].ratio*weight)<=ans) return;
	if (val+sum[now]<=ans) return;
	for (i=a[now].num;i>=0;i--) {
		if (a[now].w*i<=weight) 
			dfs(now+1,val+a[now].v*i,weight-a[now].w*i);
	}
}

int main() {
	int i,j,n,t,q;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d%lld",&m,&size);
		ll b,c;
		for (i=1;i<=m;i++) {
			scanf("%lld",&a[i].w);
			a[i].num=i;
		}
		for (i=1;i<=m;i++) {
			scanf("%lld",&a[i].v);
			a[i].ratio=(db)a[i].v/(db)a[i].w;
		}
		sort(a+1,a+m+1,cmp);
		sum[m+1]=0;
		for (i=m;i>=1;i--) {
			sum[i]=sum[i+1]+a[i].v*a[i].num;
		}
		ans=0;
		dfs(1,0,size);
		printf("%lld\n",ans);
	}
	return 0;
}
