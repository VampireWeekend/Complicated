#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <iomanip>
using namespace std;
const int maxm=30005,maxk=105;
long double dp[maxm],dp2[maxm];
struct barrier{
	int a,b;
}c[maxk];

bool cmp(barrier x,barrier y) {
	return (x.b<y.b)||(x.a<y.a&&x.b==y.b);
}

int main() {
	int m,k,n,p,i,j,top;
	scanf("%d%d%d%d",&m,&k,&n,&p);
	if (n==1) {
		if (k>0) cout << "0.000000"; else cout << "1.000000";
		return 0;
	}
	for (i=1;i<=m;i++) {
		dp[i]=0;
	}
	dp[p]=1;
	for (i=1;i<=k;i++) {
		scanf("%d%d",&c[i].a,&c[i].b);
	}
	long double sum=1.0L;
	sort(c+1,c+k+1,cmp);
	top=1;
	long double *x1,*x2;
	for (i=0;i<n;i++) {
		if (i%2==0) {
			x1=dp;
			x2=dp2;
			memset(dp2,0,sizeof(dp2));
		} else {
			x1=dp2;
			x2=dp;
			memset(dp,0,sizeof(dp));
		}
		if (c[top].a==1&&c[top].b==i) {
				sum-=*(x1+1);
				while (c[top].a==1&&c[top].b==i) top++;
	    	} else {
	    		*(x2+2)=*(x2+1)=*(x1+1)/2.0L;
	    	}
		for (j=2;j<=m-1;j++) {
			if (c[top].a==j&&c[top].b==i) {
		        sum-=*(x1+j);
				while (c[top].a==j&&c[top].b==i) top++;
	    	} else {
	    		long double z=*(x1+j)/3.0L;
	    		*(x2+j-1)+=z;
	    		*(x2+j)+=z;
	    		*(x2+j+1)+=z;
	    	}
		}
	    if (c[top].a==m&&c[top].b==i) {
		        sum-=*(x1+m);
				while (c[top].a==m&&c[top].b==i) top++;
	    	} else {
	    		*(x2+m)+=*(x1+m)/2.0L;
	    		*(x2+m-1)+=*(x1+m)/2.0L;
	    	}
/*	    for (j=1;j<=m;j++) {
	    	printf("%.3lf ",*(x2+j));
	    }
	    printf("\n");*/
	}
	if (n%2==0) {
			x1=dp;
		} else {
			x1=dp2;
		}
	for (i=1;i<=m;i++) 
		if (c[top].a==i&&c[top].b==n) {
				sum-=*(x1+i);
				while (c[top].a==i&&c[top].b==n) top++;
	    	}/* else {
	    		sum+=*(x1+i);
	    	}*/
// 	printf("%.6Lf\n",sum);
    cout << setiosflags(ios::fixed) << setprecision(6);
	cout << sum;
	return 0;
}
