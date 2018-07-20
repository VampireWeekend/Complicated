#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=70;
int a[maxn],b[maxn];

int main() {
	int n,i,j,l;
	cin >> n;
	for (i=1;i<=n/2;i++) {
		a[i]=i;
		b[i]=n-i+1;
	}
	for (l=1;l<n;l++) {
		for (j=1;j<=n/2;j++) cout << a[j] << ' ' << b[j] << ' ';
		cout << '\n';
		int k=b[1];
		for (i=n/2+1;i>=2;i--) a[i]=a[i-1];
		a[2]=k;b[n/2+1]=a[n/2+1];
		for (i=1;i<=n/2;i++) b[i]=b[i+1];
	}
	return 0;
}
