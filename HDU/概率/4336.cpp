#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db a[maxn],dp[1050005];

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		int i,j,p;
		db sum=0.0;
		for (i=0;i<n;i++) {
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		mem0(dp);
		sum=1.0-sum;
		p=(1<<n)-1;
		dp[p]=0;
		for (i=p-1;i>=0;i--) {
			db s=1,k=0;
			for (j=0;j<n;j++) {
				if (i&(1<<j)) {
					k+=a[j];
				} else {
					s+=a[j]*dp[i|(1<<j)];
				}
			}
			dp[i]=s/(1-sum-k);
		}
		printf("%.6lf\n",dp[0]);
	}
	return 0;
}
