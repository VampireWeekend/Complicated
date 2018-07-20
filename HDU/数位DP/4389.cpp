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
const int maxn=82,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int dp[11][maxn][maxn][maxn];
int num[20];

int dfs(int len,int sum,int mod,int nu,bool HaveLimit) {
    if (sum>len*9) return 0;
    if (len==0) 
        return sum==0&&nu==0;
    if (dp[len][sum][mod][nu]!=-1&&!HaveLimit) 
        return dp[len][sum][mod][nu];
        
    int p=HaveLimit?num[len]:9;
    int ans=0;
    for (int i=0;i<=p;i++) {
        ans+=dfs(len-1,sum-i,mod,(nu*10+i)%mod,HaveLimit&&i==num[len]);
    }
    if (!HaveLimit) 
        dp[len][sum][mod][nu]=ans;
    return ans;
}

int solve(int n) {
    int len=0,i;
    int k=n;
    while (k) {
        num[++len]=k%10;
        k/=10;
    }
    int ans=0;
    for (i=1;i<=min(9*len,81);i++) {
        ans+=dfs(len,i,i,0,1);
    }
    return ans;
}

int main() {
    int a,b;
    int cas,cnt=0;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&cas);
    while (scanf("%d%d",&a,&b)!=EOF) {
        cnt++;
        int ans=solve(b)-solve(a-1);
        printf("Case %d: %d\n",cnt,ans);
    }
    return 0;
}
