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
db dp[maxn][maxn]; 

int main() {
	int n,m,i,j;
while (scanf("%d%d",&n,&m)!=EOF) {
	mem0(dp);
	for (i=n;i>=0;i--) {
		for (j=m;j>=0;j--) {
			if (i==n&&j==m) continue;
			dp[i][j]=(dp[i+1][j]*(n-i)*j+dp[i][j+1]*i*(m-j)+dp[i+1][j+1]*(n-i)*(m-j)+n*m)/(n*m-i*j);
		}
	}
	printf("%.4lf\n",dp[0][0]);
}
	return 0;
}
