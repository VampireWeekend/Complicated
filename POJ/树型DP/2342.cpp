#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int maxn=6005;
int dp[maxn][2],f[maxn],v[maxn],z[maxn];
vector<int> son[maxn];

int max(int a,int b){
	if (a>b) return a; else return b;
}

void dfs(int now) {
	int size=son[now].end()-son[now].begin();
	if (size<1) {
		dp[now][0]=0;
		dp[now][1]=v[now];
		return;
	}
	
	for (int i=0;i<size;i++) {
		int node=son[now][i];
		dfs(node);
		dp[now][0]+=max(dp[node][1],dp[node][0]);
		dp[now][1]+=dp[node][0];
	}
	dp[now][1]+=v[now];
}

int main () {
	int n,i,l,k,ans=0;
	cin >> n;
    memset(z,0,sizeof(z));
    memset(dp,0,sizeof(dp));
    for (i=1;i<=n;i++) cin >> v[i];
    cin >> l >> k;
	while (l&&k) {
		f[l]=k;
		z[l]=1;
		son[k].push_back(l);
		cin >> l >> k;
	}
	int root=0;
	for (i=1;i<=n;i++) {
		if (!z[i]) {
			root=i; break;
		}
	}
	dfs(root);
	cout << max(dp[root][1],dp[root][0]);
	return 0;
}
