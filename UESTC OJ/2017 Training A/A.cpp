//RMQ
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=50005;
int a[maxn],amax[maxn][20],amin[maxn][20];
int b[20];

int main() {
	int i,n,q,k,h,j;
	scanf("%d%d",&n,&q);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		amax[i][0]=amin[i][0]=a[i];
	}
 //   b[0]=1;k=0;
 //   for (i=1;i<=18;i++) b[k]=b[k-1]*2;
	for (h=1,i=2;i<=n;h++,i*=2) {
		for (j=1;j+i-1<=n;j++){
		    amax[j][h]=max(amax[j][h-1],amax[j+i/2][h-1]);	
		    amin[j][h]=min(amin[j][h-1],amin[j+i/2][h-1]);		
	    }
	}
	int x,y,m,l;
	for (i=1;i<=q;i++) {
		h=0;k=1;
		scanf("%d%d",&x,&y);
		while (k*2<=(y-x+1)) {
			k*=2;h++;
		}
	    m=max(amax[x][h],amax[y-k+1][h]);
	    l=min(amin[x][h],amin[y-k+1][h]);
	    printf("%d\n",m-l);
	}
	return 0;
}

/*
5 3
3 2 7 9 10
1 5
2 3
3 5
*/
