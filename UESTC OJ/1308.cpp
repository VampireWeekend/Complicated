#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;
const double pi=3.1415926535;

int main() {
	int t,i;
	double r1,r2;
	cin >> t;
	for (i=1;i<=t;i++) {
		cin >> r1 >> r2;
		cout << setiosflags(ios::fixed) << setprecision(4);
		double ans=0.33333333*pi*r1*r1*r1*r1*r2*r2/(r1*r1+r2*r2)*sqrt(r1*r1+r2*r2);
		ans+=
	    printf("%f",ans);
	}
	return 0;
}
