#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
typedef long double ld;
using namespace std;
const int maxd=25;
const ld inf=1e-9;
int f[30],d,a,b,c[30];
ld ans;

void dfs(int de,int now,ld sum) {
	if (now>1000||sum-ans>=inf) return;
	if (sum+(1.0L/now*(d-de+1))<ans) return;
	if (de+ceil((ans-sum)*(ld)now)>maxd) return;
//	cout << now << ' ' << sum << ' ' << de << endl;
	if (abs(sum-ans)<inf&&(de-1<d||(de-1==d&&f[de-1]<c[de-1]))) {
		d=de-1;
		memcpy(c,f,sizeof(f));
	}
	f[de]=now;
	dfs(de+1,now+1,sum+1.0L/now);
	dfs(de,now+1,sum);
}

int main() {
	scanf("%d%d",&a,&b);
	ans=(ld)a/(ld)b;
	d=maxd;
	dfs(1,2,0L);
	for (int i=1;i<=d-1;i++) {
		printf("%d ",c[i]);
	}
	printf("%d",c[d]);
	printf("\n");
	return 0;
}
