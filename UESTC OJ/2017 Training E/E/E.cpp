#include <cstdio>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	int n,i;
	ll ans=1;
	cin >> n;
	for (i=1;i<=n;i++) {
		ans*=(ll)i;
		if (i!=n) ans*=(ll)i;
	}
	cout << ans;
}
