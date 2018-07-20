#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=150;
int i,j,ans,n,m,k;
int a[maxn][maxn],sum[maxn];
//二维最长区间和 
int max(int a,int b){
	if (a>b) return a; else return b;
}

int main () {
	cin >> n;
	for (i=1;i<=n;i++) 
	    for (j=1;j<=n;j++)
	        cin >> a[i][j];
    ans=a[1][1];
	for (i=1;i<=n;i++) {
		for (j=0;j<=n;j++) 
			sum[j]=0;
		for (j=i;j<=n;j++) {
			m=0;
			for (k=1;k<=n;k++) {
				sum[k]+=a[j][k];
		    	m=max(0,m)+sum[k];
		    	ans=max(ans,m);
			}
		}
	}
	cout << ans;
	return 0;
}
/*
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 100000

*/
