#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef double db;
const int maxk=1005,step=75;
db p[15];
int num[15];
db survive[15][maxk],die[15][maxk],ans[15];

int main() {
	int t,i,j,n,k;
	scanf("%d",&t);
	cout << setiosflags(ios::fixed) << setprecision(6);
	while (t--) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d%lf",&num[i],&p[i]);
			survive[i][0]=1.0;
		}
		if (n==1) {
			printf("1.000000\n");
			continue;
		}
		for (i=1;i<=n;i++) {
			for (j=1;j<=step;j++) {
				die[i][j]=pow(1.0-pow(p[i],j),num[i]);
		//		cout << die[i][j] << endl;
				survive[i][j]=1.0-die[i][j];
			}
		}
		for (i=1;i<=n;i++) ans[i]=0;
		for (i=1;i<=n;i++) {
			for (j=1;j<step;j++){
				db t=survive[i][j]-survive[i][j+1];
				for (k=1;k<=n;k++)
				    if (k!=i) t*=die[k][j];
				ans[i]+=t;
			}
		}
		for (i=1;i<=n;i++) {
			if (i!=n) cout << ans[i] << ' ';
			else cout << ans[i];
		}
		printf("\n");
	}
	return 0;
} 
