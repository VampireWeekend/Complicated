#include <cstdio>
#include <iostream>
using namespace std;
int n,i,j,f,v;
const int maxn=105;
int dp[maxn][maxn],a[maxn][maxn];

int max(int a,int b){
	if (a>b) return a; else return b;
}

int main(){
	cin >> f >> v;
	for (i=1;i<=f;i++)
	    for (j=1;j<=v;j++)
	        cin >> a[i][j];
	int m=-1<<30;
	for (i=1;i<=v-f+1;i++){
		m=max(m,a[1][i]);
		dp[i][1]=m;
	}
	for (j=2;j<=f;j++) {
		dp[j][j]=dp[j-1][j-1]+a[j][j];
		for (i=j+1;i<=v-f+j;i++){
	    	dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[j][i]);
	    }
	}
	int ans=-1<<30;
	for (i=f;i<=v;i++) 
	    ans=max(ans,dp[i][f]);
/*	for (i=1;i<=v;i++) {
		for (j=1;j<=f;j++)
	        cout << dp[i][j] << ' ';
	    cout << endl;
	}*/
	cout << ans;
	return 0;
}
/*
3 5
1 7 -4 4 9
5 -1 4 3 6
7 1 -5 100 1

*/
