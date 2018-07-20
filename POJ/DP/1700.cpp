#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1005;
int a[maxn];

void qsort (int x[],int l,int r) {
	int i=l,j=r;
	int mid=x[(i+j)/2];
	while (i<j) {
		while(x[i]<mid) i++;
		while(mid<x[j]) j--;
		if (i<=j) {
			int z=x[i];x[i]=x[j];x[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(x,l,j);
	if (i<r) qsort(x,i,r);
}

int main() {
	int t,j,i,q,n,m;
	scanf("%d",&t);
	for (q=1;q<=t;q++) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			cin >> a[i]; 
		}
		qsort(a,1,n);
		int k=n,sum=0;
		while (k>3) {
			m=min(a[1]+a[2]*2+a[k],a[1]*2+a[k]+a[k-1]);
			sum+=m;
			k-=2;
		}
		if (k==2) sum+=a[k]; else sum+=a[3]+a[1]+a[2];
		cout << sum << endl; 
	}
	return 0;
}
