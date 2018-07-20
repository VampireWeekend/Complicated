#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	long long l1,l2,lt,a1,a2,at,x,y;
	int n,t;
	scanf("%d",&n);
	for (t=1;t<=n;t++) {
		scanf("%lld%lld%lld%lld%lld%lld",&l1,&a1,&l2,&a2,&lt,&at);
		if (l1<a1) {
			long long z=l1;l1=a1;a1=z;
			z=l2;l2=a2;a2=z;
			z=lt;lt=at;at=z;
		}
		long long ll1=l1;
		l1*=a1;l2*=a1;lt*=a1;
		a1*=ll1;a2*=ll1;at*=ll1;
		if (l2==a2||l1==0) {
			cout << "?" << endl;
			continue;
		}
		if ((lt-at)%(l2-a2)!=0||(lt-at)/(l2-a2)<1) {
			cout << "?" << endl;
			continue;
		} else y=(lt-at)/(l2-a2);	
		if ((lt-l2*y)%l1!=0||(lt-l2*y)/l1<1) {
			cout << "?" << endl;
			continue;
		} else x=(lt-l2*y)/l1;
		printf("%lld %lld\n",x,y);
	}
	return 0;
}
