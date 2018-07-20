#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxv=100005;
const int inf=0x3f3f3f3f;
int dp[maxv],v[105],dp2[maxv];

bool cmp(int a,int b) {
    return a>b;	
}

int main() {
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	int n,m,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) 
		scanf("%d",&v[i]);
	sort(v+1,v+n+1,cmp);
	for (i=1;i<=n;i++) {
		for (j=100000;j>=1;j--) {
			if (dp[j]!=0) 
				if (dp[j+v[i]]==0) dp[j+v[i]]=dp[j]+1; 
			    //	else dp[j+v[i]]=min(dp[j+v[i]],dp[j]+1);
		}
		dp[v[i]]=1;
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++) 
		scanf("%d",&v[i]);
	sort(v+1,v+m+1,cmp);
	for (i=1;i<=m;i++) {
		for (j=100000;j>=1;j--) {
			if (dp2[j]!=0) 
				if (dp2[j+v[i]]==0) dp2[j+v[i]]=dp2[j]+1; 
		    //		else dp2[j+v[i]]=min(dp2[j+v[i]],dp2[j]+1);
		}
		dp2[v[i]]=1;
	}
	int minpack=inf;
	for (i=1;i<=100000;i++) {
		if (dp[i]!=0&&dp2[i]!=0) {
			minpack=min(minpack,dp[i]+dp2[i]);
		}
	}
	if (minpack==inf) printf("impossible"); else printf("%d",minpack);
	return 0;
}
