#include <cstdio>
#include <iostream>
using namespace std;
const int maxm=1005;
typedef long long ll;
const ll mod=1e9+7;
ll dp[maxm][1<<11],fit[1<<11];
int maxstate;

bool check(int i) {
	int cnt=0;
	while (i>0) {
		if (i%2) cnt++; else {
			if (cnt%2) return false;
			cnt=0;
		}
		i/=2;
	}
	if (cnt%2) return false; else return true;
}

bool judge(int i,int j) {
	if ((i|j)==maxstate&&fit[i&j]) return true; else return false;
}

int main() {
	int n,m,i,j,k;
	scanf("%d%d",&m,&n);
	maxstate=(1<<(n))-1;
	for (i=0;i<=maxstate;i++) {
		fit[i]=check(i);
	}
	for (i=0;i<=maxstate;i++) {
		if (judge(maxstate,i)) 
			dp[1][i]=1;
    	else dp[1][i]=0;
	}
	if (m==1||n==1) {
		if ((n+m)%2==0) cout << 0 << endl; else cout << 1 << endl;
		return 0;
	}
	for (i=2;i<m;i++) {
		for (j=0;j<=maxstate;j++) {
			dp[i][j]=0;
	    	for (k=0;k<=maxstate;k++) 
	    		if (judge(j,k)) 
		   			dp[i][j]+=dp[i-1][k];
			dp[i][j]%=mod;
	//		cout << dp[i][j] << endl;
		}
	}
	dp[m][maxstate]=0;
	for (i=0;i<=maxstate;i++) {
		if (judge(maxstate,i)) dp[m][maxstate]+=dp[m-1][i];
	}
	dp[m][maxstate]%=mod;
	cout << dp[m][maxstate] << endl;
	return 0;
}
