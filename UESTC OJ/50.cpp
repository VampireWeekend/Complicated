#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	int t,q,i,n;
	double max,min,gap,tot;
	int a[100001];
	cin >> t;
	for (q=1;q<=t;q++) {
		cin >> n;
		for (i=1;i<=n;i++) cin >> a[i];
		cin >> gap;
		min=a[1]+gap;
		tot=a[1]+gap+a[2];
		max=tot;
		for (i=3;i<=n;i++) {
			cin >> gap;
			tot+=gap;
			double newmin=tot/(double)(i-1);
			if (newmin>min) min=newmin;
			tot+=a[i];
			double newmax=tot/(double)(i-1);
			if (newmax<max) max=newmax;
		}
		if (min>max) cout << "impossible" << endl; else {
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << min << endl;
		}
	}	
	return 0;
}
