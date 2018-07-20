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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db dp[maxn];

int main() {
	int cas;
	while (scanf("%d",&cas)!=EOF) {
	while (cas--) {
		int i,n,m,t;
		scanf("%d%d%d",&t,&m,&n);
		if (t==0) {
			int ans=1;
			for (i=1;i<n;i++) {
				ans=ans*m+1;
			}
			printf("%d.000000000\n",ans);
		} else {
			db ans=0.0,p=1.0;
			for (i=1;i<=n;i++) {
				ans+=p;
				p*=(db)m/(db)(m-i);
			}
			printf("%.9lf\n",ans);
		}
	}
	}
	return 0;
}
