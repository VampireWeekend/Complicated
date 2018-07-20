#include <cstdio>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
typedef long double ld;
const ld inf=1e-40;
using namespace std;
const int maxn=10005;
ld num[maxn];

int main() {
	int m,n,b,a,i,j,k=0,ans=1;
	cin >> m >> n >> a >> b;
	for (i=b;i<=b+m-1;i++) {
		for (j=a;j<=n+a-1;j++) {
			num[++k]=i*log2l(j);
		}
	}
	sort(num+1,num+k+1);
	for (i=2;i<=k;i++) {
		if (num[i]!=num[i-1]) ans++;
	}
	cout << ans;
	return 0;
}
