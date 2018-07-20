#include <cstdio>
#include <iostream>
#include <map> 
#include <string>
#include <string.h>
using namespace std;
const int maxn=105;
string s[maxn];
int a[maxn],num[maxn];

int main() {
	int i,t,q,max,n,j,sum;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		max=0;sum=0;
		for (i=1;i<=n;i++) {
			cin >> s[i];
			int flag=0;
			for (j=1;j<=i-1;j++) {
				if (s[j]==s[i]) {
					flag=j;
					break;
				}
			}
			if (flag==0) sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
