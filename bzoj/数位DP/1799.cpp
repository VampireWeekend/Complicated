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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll dp[20][165][165];
int num[20];

ll dfs(int len,int sum,int mod,int nu,bool HaveLimit) {
	if (sum>len*9) return 0;
	if (len==0) 
	    return sum==0&&nu==0;
	if (dp[len][sum][nu]!=-1&&!HaveLimit) 
	    return dp[len][sum][nu];
	    
	int p=HaveLimit?num[len]:9;
	ll ans=0;
	for (int i=0;i<=p;i++) {
		ans+=dfs(len-1,sum-i,mod,(nu*10+i)%mod,HaveLimit&&i==num[len]);
	}
	if (!HaveLimit) 
	    dp[len][sum][nu]=ans;
	return ans;
}

ll solve(ll n) {
	int len=0,i;
	ll k=n;
	while (k) {
		num[++len]=k%10;
		k/=10;
	}
	ll ans=0;
	for (i=1;i<=9*len;i++) {
		memset(dp,-1,sizeof(dp));
		ans+=dfs(len,i,i,0,1);
	}
	return ans;
}

int main() {
	ll a,b;
	while (scanf("%lld%lld",&a,&b)!=EOF) {
		ll ans=solve(b)-solve(a-1);
		printf("%lld\n",ans);
	}
	return 0;
}

