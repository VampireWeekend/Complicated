//最长公共子序列 
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1005;
char s[maxn],t[maxn];
int dp[maxn][maxn];

int max(int a,int b) {
	if (a>b) return a; else return b;
}

int main() {
	int lens,lent,i,j;
	while (scanf("%s",s)!=EOF) {
		scanf("%s",t);
		lens=strlen(s);
		lent=strlen(t);
		int ans=0;
		for (i=0;i<=lens;i++) {
			for (j=0;j<=lent;j++) {
				if (i==0||j==0) dp[i][j]=0; else {
					if (s[i-1]==t[j-1]) {
						dp[i][j]=dp[i-1][j-1]+1;
						ans=max(ans,dp[i][j]);
					} else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		printf("%d\n",ans); 
	}
	return 0;
}
