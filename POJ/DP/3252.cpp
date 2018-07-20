#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
int num[50];
int dp[50][50][50];

ll dfs(ll len,ll one,ll zero,bool HaveLimit) {
	if (zero+len<one) return 0;
	if (!len)
	    return 1;
	if (!HaveLimit&&dp[len][one][zero]!=-1)
	    return dp[len][one][zero];
	int top;
	ll ans;
	if (HaveLimit) top=num[len]; else top=1;
	if (top==0) ans=dfs(len-1,one,zero+1,HaveLimit); 
	    else ans=dfs(len-1,one,zero+1,0);
	if (top==1) ans+=dfs(len-1,one+1,zero,HaveLimit);
	if (!HaveLimit) dp[len][one][zero]=ans;
	return ans;
}

ll solve(ll limit) {
	if (limit==-1) return -1;
	ll k=limit,cnt=0,ans=0;
	while (k) {
		num[++cnt]=k%2;
		k/=2;
	}	
	for (int i=cnt;i>=1;i--) {
		if (i==cnt) ans+=dfs(i-1,1,0,1); else ans+=dfs(i-1,1,0,0);
	}
	return ans;
}

int main() {
	ll l,r,ans;
	memset(dp,-1,sizeof(dp));
	while (scanf("%lld%lld",&l,&r)!=EOF) {
		ans=solve(r)-solve(l-1);
		printf("%lld\n",ans);
	}
	return 0;
}
