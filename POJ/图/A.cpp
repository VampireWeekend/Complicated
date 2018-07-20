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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
bool a[maxn],b[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int n,m,i,x,y,z;
	scanf("%d%d",&n,&m);
	mem0(a);mem0(b);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		if (x>y) {
			z=x;x=y;y=z;
		}
		if (x==1) a[y]=1;
		if (y==n) b[x]=1; 
	}
	for (i=2;i<n;i++) {
		if (a[i]&&b[i]) {
			cout << "POSSIBLE\n";
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}

