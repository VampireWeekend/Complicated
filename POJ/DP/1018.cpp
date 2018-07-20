#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
typedef double db;
typedef int ll;
const int maxn=110;
int dp[maxn][maxn*10],mb[maxn][maxn];
int k[maxn];
int i,j,n,t,q,l,p,b;

ll min (ll a, ll b) {
	if (a<b) return a; else return b;
}

db max (db a, db b) {
	if (a>b) return a; else return b;
}

int main(){
	cin >> l;
	for (q=1;q<=l;q++) {
	    cin >> n;
	    for (t=1;t<=400;t++) dp[0][t]=0;
		for (i=1;i<=n;i++) {
			cin >> k[i];
			for (t=1;t<=400;t++) dp[i][t]=1<<30;
			for (j=1;j<=k[i];j++) {
				cin >> b >> p;
				for (t=1;t<=b;t++) dp[i][t]=min(dp[i][t],dp[i-1][t]+p);
			}
		}
		db ans=0;
	    for (i=1;i<=400;i++) 
         	ans=max(ans,(db)i/(db)dp[n][i]);
        printf("%.3lf\n",ans);
	}
	return 0;
}
