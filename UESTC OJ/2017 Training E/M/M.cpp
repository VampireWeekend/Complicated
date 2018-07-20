#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn=1e6;
int prime[maxn+5];
ll euler[maxn+5],a[maxn+5];
int num;

void init() {
	num=0;
	memset(prime,0,sizeof(prime));
	int i,j;
	euler[1]=1;
	for (i=2;i<=maxn;i++) {
		if (!prime[i]) {
			a[++num]=i;
			euler[i]=i-1;
		}
		for (j=1;j<=num&&i*a[j]<=maxn;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0) {
				euler[i*a[j]]=euler[i]*a[j];
				break;
			} else euler[i*a[j]]=euler[i]*(a[j]-1);
		}
	}
}

int main() {
	init();
	int n,i,j,b;
	ll sum=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&b);
		if (b==1) continue;
		for (j=1;j<=sqrt(b);j++) {
			if (b%j==0) {
				sum+=euler[b/j]*(ll)j;
				if (j*j!=b&&j!=1) sum+=euler[j]*(ll)(b/j);
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
