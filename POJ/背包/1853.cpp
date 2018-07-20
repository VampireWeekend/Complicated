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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db a[maxn];
int dp[22005],pre[22005],path[22005],v[105];

int main() {
	int n;
	scanf("%d",&n);
	while (n) {
		memset(pre,-1,sizeof(pre));
		meminf(dp);
		int i,j,k=0;
		db sum=0;
		for (i=1;i<=n;i++) {
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		for (i=1;i<=n;i++) {
			v[i]=round(a[i]*20000.0/sum);
			k+=v[i];
		}
		for (i=1;i<=n;i++) {
			for (j=k;j>=v[i];j--) {
				if (dp[j-v[i]]!=inf&&dp[j]==inf) {
					dp[j]=1;
					pre[j]=j-v[i];
					path[j]=i;
				}
			}
			if (dp[v[i]]==inf) path[v[i]]=i; 
			dp[v[i]]=1;
		}
		int p=-1;
		for (i=0;;i++) {
			if (dp[k/2-i]==1) {
				p=k/2-i;
				break;
			}
		}
		stack<int> st;
		while (p!=-1) {
			st.push(path[p]);
			p=pre[p];
		}
		while (!st.empty()) {
			printf("%d ",st.top());
			st.pop();
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}

