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
const int maxn=1005,maxk=60,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll x[maxn];

struct haru {
	int val;
	ll t;
}; 
haru a[maxn];

bool cmp(haru a,haru b) {
	return a.val>b.val;
}

bool linear_basis_insert(ll p) {
	for (int i=maxk;i>=0;i--) {
		if ((p>>i)%2==1) {
			if (!x[i]) {
				x[i]=p;
				return true;
			} else p=p^x[i];
		}
	}
	return p!=0;
}

int main() {
	int n,i,sum=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%lld%d",&a[i].t,&a[i].val);
	sort(a+1,a+n+1,cmp);
	mem0(x);
	for (i=1;i<=n;i++)
		if (linear_basis_insert(a[i].t)) sum+=a[i].val;
	printf("%d\n",sum);
	return 0;
}
