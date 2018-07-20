#include <vector>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
using namespace std;
const long double pi=3.1415926535L;
const int piece=500000;

long double sqr(long double x) {
	return x*x;
}

long double fx(long double r,long double g) {
	return exp(-sqr(r)/(2*sqr(g)))/(2*pi*sqr(g));
}

int main() {
	long double a,b,c,d,e,f,g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	long double ans=0L;
	int i;
	for (i=0;i<piece;i++) {
		long double r=a*((long double)i+0.5L)/(long double)piece;
		ans+=50L*fx(r,g)*pi*2*r*a/(long double)piece;
	}
	for (i=0;i<piece;i++) {
		long double r=(b-a)*((long double)i+0.5L)/(long double)piece+a;
		ans+=25L*fx(r,g)*pi*2*r*(b-a)/(long double)piece;
	}
	for (i=0;i<piece;i++) {
		long double r=(c-b)*((long double)i+0.5L)/(long double)piece+b;
		ans+=10.5L*fx(r,g)*pi*2*r*(c-b)/(long double)piece;
	}
	for (i=0;i<piece;i++) {
		long double r=(d-c)*((long double)i+0.5L)/(long double)piece+c;
		ans+=31.5L*fx(r,g)*pi*2*r*(d-c)/(long double)piece;
	}
	for (i=0;i<piece;i++) {
		long double r=(e-d)*((long double)i+0.5L)/(long double)piece+d;
		ans+=10.5L*fx(r,g)*pi*2*r*(e-d)/(long double)piece;
	}
	for (i=0;i<piece;i++) {
		long double r=(f-e)*((long double)i+0.5L)/(long double)piece+e;
		ans+=21L*fx(r,g)*pi*2*r*(f-e)/(long double)piece;
	}
	cout << setiosflags(ios::fixed) << setprecision(10);
	cout << ans;
	return 0;
}
