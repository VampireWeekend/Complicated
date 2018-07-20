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
#define size 2
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[15];

struct Matrix {
	db a[size][size];
};

Matrix operator*(const Matrix &x,const Matrix &y) {
	int i,j,k;
	Matrix ans;
	for (i=0;i<size;i++) {
		for (j=0;j<size;j++) {
			ans.a[i][j]=0.0;
			for (k=0;k<size;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
	//			ans.a[i][j]%=m;
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
	if (index<0) return ans;
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
	int n,i;
	db p;
	while (scanf("%d%lf",&n,&p)!=EOF) {
		Matrix l;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		a[0]=0;
		l.a[0][0]=p;l.a[0][1]=1.0-p;
		l.a[1][0]=1.0;l.a[1][1]=0.0;
		db tot=1.0;
		for (i=1;i<=n;i++) {
			Matrix fp=fastpower(l,a[i]-a[i-1]-1);
			tot*=1-fp.a[0][0];
		}
		printf("%.7lf\n",tot);
	}
	return 0;
}

