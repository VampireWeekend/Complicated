#include <iostream>
#include <cstdio> 
using namespace std;
int a[1001],c[1001],l[1001],r[1001];
void qsort (int x[],int h[],int s[],int q[],int l,int r) {
	int i,j;
	int mid;
	i=l;
	j=r;
	mid=x[(i+j)/2];
	int z;
	while (i<j) {
		while(x[i]<mid) i++;
		while(mid<x[j]) j--;
		if (i<=j) {
			z=x[i];x[i]=x[j];x[j]=z;
			z=h[i];h[i]=h[j];h[j]=z;
			z=s[i];s[i]=s[j];s[j]=z;
			z=q[i];q[i]=q[j];q[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(x,h,s,q,l,j);
	if (i<r) qsort(x,h,s,q,i,r);
}

int main () {
	int i,j,n,s,sum=0,maxsum=0,minsum=0;
	int ans=0;
	cin >> n >> s;
	for (i=1;i<=n;i++) {
		cin >> a[i] >> c[i] >> l[i] >> r[i];
		maxsum+=r[i];
		minsum+=l[i];
		sum+=a[i];
	}
	if ((maxsum<s)||(minsum>s)) {
		cout << "impossible" << endl;
		return 0;
	}
	if (sum==s) {
		cout << 0 << endl;
		return 0;
	}
	qsort(c,a,l,r,1,n);
	for (i=1;i<=n;i++) {
		if (sum>s) {
			if (sum-a[i]+l[i]<=s) {
				cout << ans+(sum-s)*c[i] << endl;
				return 0;
			} else {
				ans+=(a[i]-l[i])*c[i];
				sum=sum+l[i]-a[i];
			}
		}
		if (sum<s) {
			if (sum-a[i]+r[i]>=s) {
				cout << ans+(s-sum)*c[i] << endl;
				return 0;
			} else {
				ans+=(r[i]-a[i])*c[i];
				sum=sum+r[i]-a[i];
			}
		}
	}
	return 0;
} 
