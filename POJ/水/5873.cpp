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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=20005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn],sum[maxn];

bool cmp(int a,int b) {
	return a>b;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i,cas,n;
while(scanf("%d",&cas)!=EOF) {
	while (cas--) {
		scanf("%d",&n);
		int flag=1;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1,cmp);
		int i=1;
		int u=0;
		sum[0]=0;
		for (i=1;i<=n;i++) {
			sum[i]=sum[i-1]+a[i];
			u+=2*(n-i);
			if (sum[i]>u) flag=0;
		}
		if (sum[n]!=n*(n-1)) flag=0;
		if (flag) printf("T\n"); else printf("F\n");
	} 
}
	return 0;
}

