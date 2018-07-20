#include <cstdio>
#include <iostream>
using namespace std;

long long a,b; 
int i,t;

int main () {
	cin >> t;
	for  (i=1;i<=t;i++) {
		cin >> a >> b;
		if (a<b) {
			long long z;
			z=a;a=b;b=z;
		}
		cout << a-1+(b-1)*a << endl;
	}
}
