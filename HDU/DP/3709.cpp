#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
int num[25];
ll dp[20][20][2005];

ll dfs(ll len,ll mid,ll sum,bool HaveLimit) {
	if (!len) 
	    return sum==0?1:0;
	if (sum<0) return 0;
	if (!HaveLimit&&dp[len][mid][sum]!=-1) 
	    return dp[len][mid][sum];
	    
	int limit,i;
	if (HaveLimit) limit=num[len]; else limit=9;
	ll ans=0;
	for (i=0;i<=limit;i++) {
		ans+=dfs(len-1,mid,sum+(len-mid)*i,HaveLimit&&i==limit);
	}
	if (!HaveLimit) dp[len][mid][sum]=ans;
	return ans;
}

ll solve(ll limit) {
	if (limit==-1) return 0;
	ll k=limit,cnt=0;
	while (k>0) {
		cnt++;
		num[cnt]=k%10;
		k/=10;
	}
	ll ans=0;
	for (int i=cnt;i>=1;i--) {
		ans+=dfs(cnt,i,0,1);
	}
	return ans-cnt+1;         //去除长度大于1的0 
}

int main() {
	int t,q,i,j;
	ll x,y;
	scanf("%d",&t);
	for (q=1;q<=t;q++) {
		scanf("%lld%lld",&x,&y);
		memset(dp,-1,sizeof(dp));
		ll ans=solve(y)-solve(x-1);
		printf("%lld\n",ans);
	}
	return 0;
}
