#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=15;
int a[maxn];

int main() {
	int n,i,t,q,sum;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d",&n);
		sum=0;
		int max=-1,maxi=0,maxnum=0;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if (a[i]>max) {
				max=a[i];
				maxi=i;
				maxnum=1;
			} else
			if (a[i]==max) maxnum++;
			sum+=a[i];
		}
		if (maxnum==1) {
			if (max>sum/2) printf("majority winner %d\n",maxi);
			else printf("minority winner %d\n",maxi);
		} else printf("no winner\n");
	}
	return 0;
}
