//×´Ì¬Ñ¹Ëõ 
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=105;
int map[maxn];
int dp[100][100][maxn];
int count[100];
int state[100];
char c;

int main() {
	int n,m,i,j,k,l,num=0;
	scanf("%d%d",&n,&m);
	for (k=0;k<(1<<m);k++) {
		if (((k&(k<<1))==0)&&((k&(k<<2))==0)) {
			state[++num]=k;
			j=k;
			count[num]=0;
			while (j>0) {
				count[num]+=(j%2);
				j/=2;
			}
		}
	}
	scanf("%c",&c);
	for (i=1;i<=n;i++) {
		map[i]=0;
		for (j=1;j<=m;j++) {
			scanf("%c",&c);
			if (c=='H') map[i]+=(1<<(j-1));
		}
		if (i!=n) scanf("%c",&c);
	}
	int ans=0;
	memset(dp,0,sizeof(dp));
	for (k=1;k<=num;k++) 
		if ((map[1]&state[k])==0) {
			dp[k][1][1]=count[k];
			ans=max(ans,count[k]);
		}
if (n!=1)
	for (j=1;j<=num;j++) {
		if ((map[2]&state[j])==0)
	    	for (l=1;l<=num;l++) 
		    	if ((state[j]&state[l])==0) {
		    		dp[j][l][2]=dp[l][1][1]+count[j];
		    		ans=max(ans,dp[j][l][2]);
		    	}
	}
	for (i=3;i<=n;i++) {
		for (j=1;j<=num;j++) {
		    if ((map[i]&state[j])==0)
		    for (k=1;k<=num;k++) {
		    if ((state[j]&state[k])==0) {
		    	for (l=1;l<=num;l++) 
		    		if (((state[j]&state[l])==0)&&((state[k]&state[l])==0)) 
		    		    dp[j][k][i]=max(dp[j][k][i],dp[k][l][i-1]+count[j]);
		    	ans=max(ans,dp[j][k][i]);
		    }
		    }
		}
	}
	printf("%d",ans);
	return 0;
} 
