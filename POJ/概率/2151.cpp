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
db a[maxn][35],dp[maxn][35]; 

int main() {
	int n,m,t;
	scanf("%d%d%d",&m,&n,&t);
	while (n) {
		int i,j,k;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				scanf("%lf",&a[i][j]);
			}
		}
		mem0(dp);
		for (i=1;i<=n;i++) {
			dp[i][0]=1.0;
			for (j=1;j<=m;j++) {
				for (k=m;k>=1;k--) {
					dp[i][k]=dp[i][k-1]*a[i][j]+dp[i][k]*(1-a[i][j]);
				}
				dp[i][0]=dp[i][0]*(1-a[i][j]);
			}
		}
		db s1,s2;
		s1=1.0;
		for (i=1;i<=n;i++) {
			s1*=1.0-dp[i][0];
		}
		s2=1.0;
		for (i=1;i<=n;i++) {
			db sum=0.0;
			for (j=1;j<=t-1;j++) {
				sum+=dp[i][j];
			}
			s2*=sum;
		}
		printf("%.3lf\n",s1-s2);
		scanf("%d%d%d",&m,&n,&t);
	}
	return 0;
}
