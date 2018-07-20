#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
const int maxn=1e6+1;
int a[maxn];
string s;
#define PI 3.141592654
#define E 2.71828182846
int factorial(int n)
{
    int s=1;
    if(n>3)
        s=log10(2*PI*n)/2+n*log10(n/E)+1;
    return s;
}

int main() {
	int i,sum=1;
	cin >> s;
	a[0]=0;
	int k;
	if (s.length()<=3) {
		if (s=="1") cout << 1;
		if (s=="2") cout << 2;
		if (s=="6") cout << 3;
		if (s=="24") cout << 4;
		if (s=="120") cout << 5;
		if (s=="720") cout << 6;
	} else {
		long long len=s.length();
		int i;
		for (i=7;i<=1e6;i++) {
			if (factorial(i)==len) {
				cout << i;
				return 0;
			}
		}
	} 
	return 0;
}
// 10888869450418352160768000000
