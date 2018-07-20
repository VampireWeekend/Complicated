//²©ÞÄÂÛ 
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1005;
int p[maxn];

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
	int t,q,i;
	cin >> t;
	for (q=1;q<=t;q++) {
		cin >> n;
		for (i=1;i<=n;i++) cin >> p[i];
		qsort(p,1,n);
		k=1;
		while (p[k]==k) k++;
		
	}
	return 0;
}
