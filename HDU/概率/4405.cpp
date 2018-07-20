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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
vector<int> v[maxn],d[maxn];
db dp[maxn];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	while (n||m) {
		int i,j,x,y;
		for (i=1;i<=m;i++) {
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			d[y].push_back(x);
		}
		dp[n]=0.0;
		for (i=n-1;i>=0;i--) {
			dp[i]=0.0;
			if (v[i].size()!=0) {
				dp[i]=dp[v[i][0]];
				continue;	
			}
			for (j=i+1;j<=min(n,i+6);j++) {
//				if (d[j].size()!=0) continue;
				dp[i]+=dp[j]*1.0/6.0;
			}
			dp[i]+=1.0;
		}
		printf("%.4lf\n",dp[0]);
		for (i=1;i<=n;i++) v[i].clear(),d[i].clear();
		scanf("%d%d",&n,&m);
	}
	return 0;
}
