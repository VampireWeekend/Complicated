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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn],b[maxn][maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int ans=0,i,j,n,lena,lenb,k;
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		mem0(b);
		for (i=1;i<=n;i++) {
			k=a[i];lena=0;
			while (k) {
				b[i][++lena]=k%2;
				k/=2;
			}
			b[i][0]=lena;
		}
		for (i=1;i<=n;i++) {
			for (j=1;j<i;j++) {
				int sum=0;
				for (k=1;k<=max(b[i][0],b[j][0]);k++) {
					if (b[i][k]!=b[j][k]) sum++;
				}
				ans=max(ans,sum);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

