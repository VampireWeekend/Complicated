#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn];

int gcd(int a,int b) {
	int x=a,y=b,z;
	if (x<y) {
		z=x;x=y;y=z;
	}
	while (y) {
		z=x;x=y;y=z%y;
	}
	return x;
}

int main() {
	int n,i,j,k,m;
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	m=j=a[1];
	for (i=2;i<=n;i++) {
		scanf("%d",&a[i]);
		j=gcd(j,a[i]);
		m=max(m,a[i]);
	}
	if (k%j==0&&k<=m) {
		printf("POSSIBLE");
	} else printf("IMPOSSIBLE");
	return 0;
}

