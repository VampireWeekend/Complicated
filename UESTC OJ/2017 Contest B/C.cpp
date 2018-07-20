#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=100005;
int a[maxn],x[maxn],y[maxn],q[maxn];

int main() {
	int t,h,n,i,j;
	scanf("%d",&h);
	int flag;
	for (t=1;t<=h;t++) {
		flag=0;
		memset(q,0,sizeof(q));
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d%d",&x[i],&y[i]);
			if (!q[x[i]]||!q[y[i]]) {
				if (!q[x[i]]) q[x[i]]=1; else q[y[i]]=1;
			}
			 else {
			 	flag=1;
			 	for (j=i+1;j<=n;j++) scanf("%d%d",&x[j],&y[j]);
			 	break;
			 }
		}
		if (flag) printf("impossible\n"); else printf("possible\n");
	/*	for (j=1;j<=i;j++) {
			m[x[j]].clear();
			m[y[j]].clear();
		}*/
	}
	return 0;
}
