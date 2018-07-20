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
typedef double db;
const int maxn=205,maxk=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db pi=acos(-1.0),eps=1e-4;  
int x[maxn],y[maxn],head[maxn],color[maxn],dfn[maxn];
int num,cnt;

struct Edge {
	int from,to,pre;
};
Edge edge[maxk*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

int sqr(int x) {
	return x*x;
}

db dis(int i,int j) {
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

void buildmap(int n,db mid) {
	int i,j;
	num=0;memset(head,-1,sizeof(head));
	for (i=0;i<n*2;i++) 
		for (j=i+1;j<n*2;j++) {
			if (i/2==j/2) continue;
			if (dis(i,j)<=mid)
				addedge(i,j^1),addedge(j,i^1);
		}
}

bool dfs(int now) {
	if (color[now]==1) return true;
	if (color[now]==2) return false;
	color[now]=1;color[now^1]=2;
	dfn[++cnt]=now;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!dfs(to)) return false;
	}
	return true;
}

bool check(int n) {
	mem0(color);
	int i,j;
	for (i=0;i<n;i++) {
		if (!color[i*2]) {
			cnt=0;
			if (!dfs(i*2)) {
				for (j=1;j<=cnt;j++) color[dfn[j]]=color[dfn[j]^1]=0;
				if (!dfs(i*2+1)) return false;
			}
		}
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		int i;
		for (i=0;i<2*n;i++) 
			scanf("%d%d",&x[i],&y[i]);
		db l=1e-2,r=40000.0,ans=0.0,mid;
		while (fabs(r-l)>eps) {
			mid=(l+r)/2.0;
			buildmap(n,mid);
			if (check(n)) ans=mid,l=mid; else r=mid;
		}
		ans/=2.0;
		printf("%.2lf\n",ans);
	}
	return 0;
}

