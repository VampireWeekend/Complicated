#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

void qsort (int x[],int l,int r) {
	int i,j;
	float mid;
	i=l;
	j=r;
	mid=x[(i+j)/2];
	float z;
	while (i<j) {
		while(x[i]<mid) i++;
		while(mid<x[j]) j--;
		if (i<=j) {
			z=x[i];x[i]=x[j];x[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(x,l,j);
	if (i<r) qsort(x,i,r);
}
int main(){
	int n,i,j,k,m;
	int f[1001];
	int price[1001];
	cin >> n;
	while (n!=0){
		//init
		for (i=1;i<=n;i++) 
			cin >> price[i];
		cin >> m;
		qsort(price,1,n);
		//DP		
		memset(f,0,sizeof(f));
		for (i=1;i<n;i++) {
			for (j=m-5;j>=price[i];j--){
				if (f[j]<f[j-price[i]]+price[i]) f[j]=f[j-price[i]]+price[i];
			}
		}
		if (m>=5) cout << m-price[n]-f[m-5] << endl; else cout << m << endl;
		
		cin >> n;
	}
	return 0;
}
