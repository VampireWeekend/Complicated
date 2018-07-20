#include <iostream>
#include <cstdio> 
using namespace std;

int main() {
	int n,k,i;
	cin >> n >> k;
	int now=1;
	int flag=1;
	for (i=k;i>=1;i--) {
		cout << now << ' ';
		now=now+i*flag;
		flag=flag*(-1);
	}
	if (k+1!=n) cout << now << ' '; else cout << now;
	for (i=k+2;i<=n-1;i++) {
		cout << i << ' ';
	}
	if (k+1<n) cout << n;
	return 0;
}
