#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=500;
int a[maxn],b[maxn];

void qsort(int a[],int l,int r) {
	int i=l;
	int j=r;
	int mid=a[(l+r)/2+1];
	while (i<j) {
		while (a[i]<mid) i++;
		while (mid<a[j]) j--;
		if (i<=j) {
			int z=a[i];a[i]=a[j];a[j]=z;
			i++;j--;
		}
	}
	if (l<j) qsort(a,l,j);
	if (i<r) qsort(a,i,r);
}

int main () {
    int t,i,j,q,ka,kb,n;
	cin >> t;
	for (q=1;q<=t;q++) {
		cin >> n;
		for (i=1;i<=n;i++) {
			cin >> a[i] >> b[i];
			if (a[i]>b[i]) {
				int z=a[i];a[i]=b[i];b[i]=z;
			}
			a[i]=(a[i]+1)/2;
			b[i]=(b[i]+1)/2;
		}
		qsort(a,1,n);
		qsort(b,1,n);
		ka=1;kb=1;
		int sum=0,ans=0;
		for (i=1;i<=200;i++) {
			while (a[ka]==i&&ka<=n) {
				sum++;
				ka++;
			}
			ans=max(ans,sum);
			while (b[kb]==i&&kb<=n) {
				sum--;
				kb++;
			}
		}
		cout << ans*10 << endl;
	}
	return 0;
}
