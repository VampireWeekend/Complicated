#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=50005;
int a[maxn],ma[maxn][20],mi[maxn][20];
//RMQÄ£°å 
int max(int a,int b) {
	if (a>b) return a; else return b;
}
int min(int a,int b) {
	if (a>b) return b; else return a;
}

int main () {
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		ma[i][0]=a[i];
		mi[i][0]=a[i];
	}
	for (j=1;(1<<(j))<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		}
	}
	int l,r;
	for (i=1;i<=q;i++) {
		scanf("%d %d",&l,&r);
		int k=0;
		while ((1<<(k+1))<=(r-l+1)) k++;
		int fmax=max(ma[l][k],ma[r-(1<<k)+1][k]);
		int fmin=min(mi[l][k],mi[r-(1<<k)+1][k]);
		printf("%d\n",fmax-fmin);
	}
	return 0;
}
