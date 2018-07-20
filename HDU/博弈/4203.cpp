#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,k,i,ans;
		scanf("%d%d",&n,&k);
		if (k>n) ans=0; else {
			if (k%2) {
				if (n%2) ans=1; else ans=0;
			} else {
				if ((n+1)%(k+1)==0) ans=k; else 
				    if (((n+1)%(k+1))%2) ans=0; else ans=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
