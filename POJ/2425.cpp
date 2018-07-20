#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
const int maxn=1005;
int edge[maxn][15];
int dp[maxn];

int main() {
	int n,i,j,m;
	while (scanf("%d",&n)!=EOF) {
		for (i=1;i<=n;i++) {
			scanf("%d",&edge[i][0]);
			for (j=1;j<=edge[i][0];j++) {
				scanf("%d",&edge[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		dfs
	}
	return 0;
}
