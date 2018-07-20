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
const int maxn=55,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];
ll dp[105];
bool ans[51][51][51];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m=0,x,i,j,k,I,J;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		mem0(ans);
		for (i=1;i<=n;i++) {
			for (j=i;j<=n;j++) {
				for (k=j;k<=n;k++) {
					mem0(dp);
					for (I=1;I<=n;I++) {
						if (I==i||I==j||I==k) continue;
						for (J=87;J>=a[I];J--) {
							dp[J]=dp[J]|(dp[J-a[I]]<<1);
						}
						dp[a[I]]=dp[a[I]]|1;
					}
					if ((dp[87]>>9)%2==1) ans[i][j][k]=1;
				} 
			}
		}
		int y,z,q;
		scanf("%d",&q);
		for (i=1;i<=q;i++) {
			scanf("%d%d%d",&x,&y,&z);
			if (y<x) swap(x,y);
			if (z<x) swap(z,x);
			if (z<y) swap(z,y);
			if (ans[x][y][z]) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}
