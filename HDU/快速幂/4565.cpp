#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int size=2;
ll m;

struct Matrix {
	ll a[size][size];
};

Matrix operator*(const Matrix &x,const Matrix &y) {
	int i,j,k;
	Matrix ans;
	for (i=0;i<size;i++) {
		for (j=0;j<size;j++) {
			ans.a[i][j]=0;
			for (k=0;k<size;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
				ans.a[i][j]%=m;
			}
		}
	} 
	return ans;
}

Matrix fastpower(Matrix base,ll index) {
	Matrix ans,now;
	int i,j;
	for (i=0;i<size;i++) {
		for (j=0;j<size;j++) {
			if (i==j) ans.a[i][j]=1; else ans.a[i][j]=0;
		}
	}
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		now=now*now;
		k/=2;
	}
	return ans;
}

int main() {
	ll a,b,n;
	while (scanf("%lld%lld%lld%lld",&a,&b,&n,&m)!=EOF) {
		Matrix x;
		x.a[0][0]=x.a[1][1]=a;
		x.a[0][1]=b;x.a[1][0]=1;
		Matrix sum=fastpower(x,n);
		ll ans=sum.a[0][0];
		ans*=2;
		ans%=m;
		printf("%lld\n",ans);
	}
	return 0;
}
