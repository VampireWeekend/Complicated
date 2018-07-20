#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db eps=1e-10;
int head[maxn];
db a[maxn],b[maxn],c[maxn],dp[maxn],k[maxn],e[maxn],son[maxn];
bool visit[maxn];
int num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

bool dfs(int now,int fa) {
	visit[now]=1;
	a[now]=b[now]=c[now]=0.0;
	if (fa!=0) son[now]=1.0; else son[now]=0.0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			son[now]+=1.0;
			if (!dfs(to,now)) return false;
			a[now]+=a[to];
			b[now]+=b[to];
			c[now]+=c[to];
		}
	}
	b[now]=1.0-b[now]*(1.0-k[now]-e[now])/son[now];
	a[now]=a[now]*(1.0-k[now]-e[now])/son[now]+k[now];
	c[now]=c[now]*(1.0-k[now]-e[now])/son[now]+(1.0-k[now]-e[now]);
	if (b[now]>eps) a[now]/=b[now],c[now]/=b[now]; else return false;
	b[now]=(1.0-k[now]-e[now])/(son[now]*b[now]);
	return true;
}

int main() {
	int cas,ca=0;
	scanf("%d",&cas);
	while (cas--) {
		ca++;
		num=0;memset(head,-1,sizeof(head));
		int i,j,x,y,n;
		scanf("%d",&n);
		for (i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		for (i=1;i<=n;i++) {
			scanf("%lf%lf",&k[i],&e[i]);
			k[i]/=100.0;e[i]/=100.0;
		}
		mem0(visit);
		if (!dfs(1,0)) printf("Case %d: impossible\n",ca); else {
			if (fabs(1.0-a[1])>eps) {
				db ans=c[1]/(1.0-a[1]);
				printf("Case %d: %.6lf\n",ca,ans);
			} else printf("Case %d: impossible\n",ca);
		}
	}
	return 0;
}
