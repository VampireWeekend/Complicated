//区间DP入门 
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int maxn=105;
int dp[maxn][maxn];

int main() {
	string s;
	cin >> s;
	while (s!="end") {
		int i,j,k,l,len=s.length();
		memset(dp,0,sizeof(dp));
		for (i=1;i<len;i++) {
			for (j=0,k=i;k<len;j++,k++) {
				if ((s[j]=='('&&s[k]==')')||(s[j]=='['&&s[k]==']')) {
					dp[j][k]=dp[j+1][k-1]+2;
				}
				for (l=j;l<k;l++)
				    dp[j][k]=max(dp[j][k],dp[j][l]+dp[l+1][k]);
			}
		}
		printf("%d\n",dp[0][len-1]);
		cin >> s;
	}
	return 0;
}
