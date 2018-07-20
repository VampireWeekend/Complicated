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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
db dp[maxn][maxn];

int main() {
	int n,m,k,i,j;
	db p1,p2,p3,p4;
	while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
		scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
		if (p4<1e-6) {
			printf("0.00000\n");continue;
		}
		p2/=1.0-p1;p3/=1.0-p1;p4/=1.0-p1;
		dp[1][1]=p4/(1.0-p2);
		for (i=2;i<=n;i++) {
			dp[i][i]=pow(p2,i-1)*p4;
			for (j=2;j<=min(k,i);j++) 
			    dp[i][i]+=pow(p2,i-j)*(p3*dp[i-1][j-1]+p4);
			for (j=min(k,i)+1;j<=i;j++) 
			    dp[i][i]+=pow(p2,i-j)*p3*dp[i-1][j-1];
			dp[i][i]/=1-pow(p2,i);
			dp[i][1]=p2*dp[i][i]+p4;
			for (j=2;j<=min(k,i);j++) 
			    dp[i][j]=p2*dp[i][j-1]+p3*dp[i-1][j-1]+p4;
			for (j=min(k,i)+1;j<=i;j++) 
			    dp[i][j]=p2*dp[i][j-1]+p3*dp[i-1][j-1];
		}
		printf("%.5lf\n",dp[n][m]);
	}
	return 0;
}

