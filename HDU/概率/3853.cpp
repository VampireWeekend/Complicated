#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db a[maxn][maxn][3],dp[maxn][maxn];

int main() {
	int n,m,i,j;
while (scanf("%d%d",&n,&m)!=EOF) {
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			scanf("%lf%lf%lf",&a[i][j][0],&a[i][j][1],&a[i][j][2]);
		}
	}
	mem0(dp);
	for (i=n;i>=1;i--) {
		for (j=m;j>=1;j--) {
			if (i==n&&j==m) continue;
			db u=a[i][j][0],b=a[i][j][1],c=a[i][j][2];
			dp[i][j]=(b*dp[i][j+1]+c*dp[i+1][j]+2)/(1-u);
			if (dp[i][j]>1e7) dp[i][j]=0.0;
		}
	}
	printf("%.3lf\n",dp[1][1]);
}
	return 0;
}
