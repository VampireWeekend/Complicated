#include <iostream>
#include <cstdio> 
using namespace std;

void qsort (float x[],float h[],int l,int r) {
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
			z=h[i];h[i]=h[j];h[j]=z;
			i++;j--;
		}
	} 
	if (l<j) qsort(x,h,l,j);
	if (i<r) qsort(x,h,i,r);
}

int main ()
{
	int n,i;
	float a,t;
	float x[100001],h[100001];
	char c;
	while (scanf("%d",&n)!=EOF && n) {
		for (i=1;i<=n;i++) cin >> x[i] >> h[i];
		cin >> c; t=float((int)c-48);
		cin >> c;
		cin >> c; a=float((int)c-48);
		qsort(x,h,1,n);
		float max=a*h[1]/t+x[1];
		int ans=1;
		for (i=2;i<=n;i++){
			float h2=(max-x[i])*t/a;
			if (h2<h[i]) ans++;
			float s2=a*h[i]/t+x[i];
			if (max<s2) max=s2;
		}
		cout << ans << endl;
	}
	return 0;
}
