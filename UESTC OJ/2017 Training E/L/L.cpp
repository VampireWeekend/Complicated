#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
const ll mod=1e9+7;
ll a[maxn][maxn];

int main() {
	int t,n,k,q,i,j;
	scanf("%d",&t);
	for (i=1;i<=maxn-5;i++) {
		a[i][0]=0;a[i][i]=1;
		for (j=1;j<i;j++) {
			a[i][j]=((ll)j)*a[i-1][j]+a[i-1][j-1];
			a[i][j]%=mod;
		}
	}
	for (q=1;q<=t;q++) {
		cin >> n >> k;
		cout << a[n][k] << endl; 
	}
	return 0;
}
