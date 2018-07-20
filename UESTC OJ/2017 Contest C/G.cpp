#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=1005;
char a[maxn],b[maxn];

int main() {
	int n,i,j;
	char c;
	cin >> n;
	scanf("%s",a);
	scanf("%s",b);
	int flag=1;
	if ((n%2)==1) {
		for (i=0;i<strlen(a);i++) 
		    if (a[i]==b[i]) flag=0;
	} else {
		for (i=0;i<strlen(a);i++) 
		    if (a[i]!=b[i]) flag=0;
	}
	if (flag) cout << "Deletion succeeded"; else cout << "Deletion failed";
	return 0;
}
