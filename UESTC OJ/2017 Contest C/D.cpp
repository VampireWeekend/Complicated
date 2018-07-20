#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1000005,inf=0x3f3f3f3f;
int ma[2005],mi[2005];

int sqr(int x) {
	return x*x;
}

int main() {
//	memset(mi,sizeof(mi),0x3f);
	int n,i,j,k,x,y;
	scanf("%d",&n);
	for (i=0;i<=2000;i++) {
		ma[i]=-inf;
		mi[i]=inf;
	}
	for (i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		ma[x+1000]=max(ma[x+1000],y);
		mi[x+1000]=min(mi[x+1000],y);
	}
	double ans=-1;
	for (i=0;i<=2000;i++) {
		if (ma[i]==-inf) continue;
		for (j=0;j<=2000;j++) {
			if (mi[j]!=inf) {
				ans=max(ans,sqrt(sqr(abs(i-j))+sqr(abs(ma[i]-mi[j]))));
			}
		}
	}
	printf("%.8lf",ans);
	return 0;
}
