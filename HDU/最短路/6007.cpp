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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int d[maxn],dp[10005],p[maxn];
bool inque[maxn];
queue<int> q;
vector<int> v[maxn];
int m,n,k;

struct Edge {
    int to,num;
    vector<pair<int,int> > f;
};
Edge e[maxn];

void spfa() {
	int i,j;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (i=0;i<v[now].size();i++) {
			ll sum=0,k=v[now][i],to=e[k].to;
			for (j=0;j<e[k].f.size();j++)
				sum+=d[e[k].f[j].first]*e[k].f[j].second;
			if (sum<d[to]) {
				d[to]=sum;
				if (!inque[to]) q.push(to),inque[to]=1;
			}
		}
	}
}

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		int i,j,t,x,y;
		scanf("%d%d%d",&m,&n,&k);
		mem0(inque);
		for (i=1;i<=n;i++) {
			v[i].clear();
			scanf("%d",&t);
			if (t==0) {
				scanf("%d",&p[i]);
				d[i]=m+1;
			} else {
				scanf("%d%d",&d[i],&p[i]);
				q.push(i);
				inque[i]=true;
			}
		}
		for (i=1;i<=k;i++) {
			scanf("%d%d",&e[i].to,&e[i].num);
			e[i].f.clear();
			for (j=1;j<=e[i].num;j++) {
				scanf("%d%d",&x,&y);
				e[i].f.push_back(make_pair(x,y));
				v[x].push_back(i);
			}
		}
		spfa();
		mem0(dp);
		for (i=1;i<=n;i++) {
			for (j=d[i];j<=m;j++) 
				dp[j]=max(dp[j],dp[j-d[i]]+p[i]);
		}
		printf("Case #%d: %d\n",cnt,dp[m]);
	}
	return 0;
}
