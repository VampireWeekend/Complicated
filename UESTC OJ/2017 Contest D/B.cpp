#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
ll a[maxn],b[maxn];

int main() {
	ll x,y,n,val,t=0;
	scanf("%lld%lld%lld",&x,&y,&n);
	while (x|y|n) {
		while (!n) scanf("%lld%lld%lld",&x,&y,&n);
		t++;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int i,j;
		for (i=1;i<=n;i++) {
			scanf("%lld",&val);
			ll *p=a,mod=x;
			while (*(p+(val%mod))!=0) {
				ll k=val;
				val=*(p+(val%mod));
				*(p+(val%mod))=k;
				if (mod==x) {
					p=b;
					mod=y;
				} else {
					p=a;
					mod=x;
				}
			}
			*(p+(val%mod))=val;
		}
		int flag=0,flag1=0,flag2=0;
		for (i=0;i<x;i++) {
			if (a[i]!=0) {
				if (!flag) {
					printf("Case %lld:\n",t);
					flag=1;
				}
				if (!flag1) {
					printf("Table 1\n");
					flag1=1;
				}
				printf("%d:%lld\n",i,a[i]);
			}
		}
		for (i=0;i<y;i++) {
			if (b[i]!=0) {
				if (!flag) {
					printf("Case %lld:\n",t);
					flag=1;
				}
				if (!flag2) {
					printf("Table 2\n");
					flag2=1;
				}
				printf("%d:%lld\n",i,b[i]);
			}
		}
		scanf("%lld%lld%lld",&x,&y,&n);
	}
}
