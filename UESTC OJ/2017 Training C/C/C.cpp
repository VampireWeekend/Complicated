#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
struct Matrix {
	ll v[5][5];
};

Matrix multiply(Matrix a,Matrix b) {
	int i,j,k;
	Matrix ans;
	for (i=0;i<=4;i++) {
		for (j=0;j<=4;j++) {
			ans.v[i][j]=0;
			for (k=0;k<=4;k++)
			    ans.v[i][j]+=a.v[i][k]*b.v[k][j];
			ans.v[i][j]%=mod;
		}
	}
	return ans;
}

Matrix fastpower(Matrix a,ll power) {
	Matrix ans,now=a;
	ll k=power;
	int i,j;
	for (i=0;i<=4;i++) 
		for (j=0;j<=4;j++) 
			if (i==j) ans.v[i][j]=1; else ans.v[i][j]=0;
	while (k) {
		if (k%2) ans=multiply(ans,now);
		now=multiply(now,now);
		k/=2;
	}
	return ans;
}

ll fp(ll a,ll power) {
	ll ans,now;
	ans=1;
	now=a;
	ll k=power;
	while (k) {
		if (k%2) ans*=now;
		ans%=mod;
		k/=2;
		now*=now;
		now%=mod;
	}
	return ans;
}

int main() {
	Matrix m;
	int i,j;
	ll n,tot,b,ans;
	scanf("%lld",&n);
	ll a[5][5]={{1,0,0,1,0},{3,0,0,3,0},{0,1,1,0,1},{0,1,1,0,1},{0,2,2,0,1}};
	for (i=0;i<=4;i++) {
		for (j=0;j<=4;j++) {
			m.v[i][j]=a[i][j];
		}
	}
	m=fastpower(m,n-3);
	b=0;
	tot=fp(4,n);
	ll r[5]={4,12,12,12,24};
	for (i=0;i<=4;i++) 
		for (j=0;j<=4;j++) {
			b+=r[j]*m.v[i][j];
			b%=mod;
		}
	ans=tot-b;
	ans%=mod;
	if (ans<0) ans+=mod;
	cout << ans << endl; 
	return 0;
}
