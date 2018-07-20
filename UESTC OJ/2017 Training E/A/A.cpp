#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
typedef long double ld;
typedef double db;
using namespace std;
const int maxn=105,maxk=16384;
int a[maxn],b[maxn],sg[maxk+5],s[maxk+5];

int main() {
	int k,n,m,i,j;
	scanf("%d",&n);
	memset(sg,-1,sizeof(sg));
	for (i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	sg[0]=0;
	sort(a+1,a+n+1);
	for (i=1;i<=maxk;i++) {
		memset(s,0,sizeof(s));
		for (j=1;j<=n&&a[j]<=i;j++) {
			s[sg[i-a[j]]]=1;
		}
		for (j=0;j<=i&&sg[i]==-1;j++) {
			if (!s[j]) sg[i]=j;
		}
	}
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&m);
		int sum=0;
		for (j=1;j<=m;j++) {
			scanf("%d",&k);
			sum=sum^sg[k];
		}
		if (sum==0) printf("lose!\n"); else printf("win!\n");
	}
	return 0;
}
