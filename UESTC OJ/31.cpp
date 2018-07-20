#include <cstdio>
#include <iostream>
using namespace std;

void qsort (int h[],int l,int r) {
	int i,j;
	int mid,z;
	i=l;
	j=r;
	mid=h[(i+j)/2];
	while (i<j) {
		while(h[i]<mid) i++;
		while(mid<h[j]) j--;
		if (i<=j) {
			z=h[i];h[i]=h[j];h[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(h,l,j);
	if (i<r) qsort(h,i,r);
}

int main (){
	int n,i,j,min,k,m;
	int f[1001][1001];
	int price[1001];
	cin >> n;
	while (n!=0){
		//init
		for (i=1;i<=n;i++) cin >> price[n];
		qsort(price,1,n);
		cin >> m;
		min=m;
		//DP
		for (i=0;i<=n;i++) f[i][0]=m;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++){
				f[i][j]=m;
				for (k=j;k<=i;j++) {
				    if (f[k][j-1]>=5) {
				    	if(f[k][j-1]-price[n]<f[i][j]) f[i][j]=f[k][j-1]-price[n];
				    }
					if (f[k][j]<f[i][j]) f[i][j]=f[k][j-1];
			    }				
			}
		}
		cout << f[n][n];
		cin >> n;
	}
	return 0;
}
