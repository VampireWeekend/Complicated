#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,i;
	cin >> n;
	string s;
	for (i=1;i<=n;i++) {
		cin >> s;
		cout << s.length() << endl;
	}
	return 0;
}
