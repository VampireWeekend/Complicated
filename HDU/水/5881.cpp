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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	ll l,r;
	while (scanf("%lld%lld",&l,&r)!=EOF) {
		if (l<=1&&r<=1) {
			printf("0\n");continue;
		}
		if ((l==0&&r==2)||(l==1&&r==2)||(l==2&&r==2)) {
			printf("1\n");continue;
		}
		if (l==0) {
			printf("%lld\n",(r+1)/2);continue;
		}
		if (r-l<=3) {
			printf("2\n");continue;
		}
		ll ans=(r-l-2)/2+2;
		printf("%lld\n",ans);
	} 
	return 0;
}
