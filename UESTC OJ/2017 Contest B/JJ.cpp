#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn=25;
string s[maxn];
double w[maxn],b[maxn];

int main() {
	int n,i,q,t;
	double m,d,p;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d%lf%lf",&n,&d,&p);
		printf("Recipe # %d\n",t);
		for (i=1;i<=n;i++) {
			cin >> s[i] >> w[i] >> b[i];
			if (b[i]==100) m=w[i];
		}
		m*=(p/d);
		for (i=1;i<=n;i++) {
			cout << s[i] << ' ';
			printf("%.1lf\n",b[i]*m/100.0);
		}
		for (i=1;i<41;i++) printf("-");
		printf("\n");
	}
    return 0;
}
