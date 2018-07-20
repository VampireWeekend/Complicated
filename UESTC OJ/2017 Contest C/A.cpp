#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=100005;
int a[maxn];

bool cmo(int a,int b) {
	return a>b;
}

int main() {
	int n,i,j; 
	cin >> n;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmo);
	j=a[1]+1;
	for (i=1;i<=n;i++) j=max(j,a[i]+i);
	cout << (j+1);
	return 0;
}
