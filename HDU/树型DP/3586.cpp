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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int num,m;
int dp[maxn],head[maxn];
bool visit[maxn];

struct Edge {
	int from,to,dist,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to,int dist) {
	edge[num]=(Edge){from,to,dist,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,dist,head[to]};
	head[to]=num++;
}

bool dfs(int now,int md) {
	dp[now]=0;
	visit[now]=1;
	bool f=true;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) { 
		    int p=inf; 
			if (dfs(to,md)) p=min(p,dp[to]); 
			if (edge[i].dist<=md) p=min(p,edge[i].dist);
			if (p==inf) f=false; else dp[now]+=p;
		}
	}
	if (now==1) {
		if (!f) return false; else return true;
	}
	if (dp[now]==0||!f) return false; else return true;
	return true;
}

int solve(int n) {
	int l=1,r=1000,mid,ans=-1;
	while (l<=r) {
		mid=(l+r)/2;
		mem0(visit);
		if (dfs(1,mid)) {
			if (dp[1]<=m) {
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		} else l=mid+1;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d%d",&n,&m);
	while (n!=0||m!=0) {
		num=0;
		memset(head,-1,sizeof(head));
		int i,j,x,y,d;
		for (i=1;i<n;i++) {
			scanf("%d%d%d",&x,&y,&d);
			addedge(x,y,d);
		}
		int ans=solve(n);
		printf("%d\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}

