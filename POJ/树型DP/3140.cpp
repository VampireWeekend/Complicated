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
int num;
ll a[maxn],tot,ans;
int head[maxn];
bool visit[maxn];

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*5];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

ll fuck(ll x) {
	if (x>0) return x; else return -x;
}

ll dfs(int now) {
	ll sum=a[now];
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			sum+=dfs(to);
	}
	ans=min(ans,fuck(tot-2*sum));
	return sum;
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt=0;
	while (n!=0||m!=0) {
		cnt++;
		int i,j,x,y;
		num=0;
		memset(head,-1,sizeof(head));
		tot=0;
		for (i=1;i<=n;i++) {
			scanf("%I64d",&a[i]);
			tot+=a[i];
		}
		for (i=1;i<=m;i++) {
		    scanf("%d%d",&x,&y);
			addedge(x,y);	
		}
		mem0(visit);
		ans=tot;
		dfs(1);
		printf("Case %d: %I64d\n",cnt,ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}

