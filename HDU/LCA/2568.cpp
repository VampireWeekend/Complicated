//LCA
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
const int maxn=40005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],f[maxn],dist[maxn],a[maxn*2],mind[maxn*2][20],dep[maxn*2];
bool visit[maxn];
int dfn,num;

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,int dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void dfs(int now,int step) {
	f[now]=++dfn;a[dfn]=now;dep[dfn]=step;
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dist[to]=dist[now]+edge[i].dist;
			dfs(to,step+1);
			a[++dfn]=now;
			dep[dfn]=step;
		}
	}
}

void init(int n) {
	mem0(mind);
	int i,j;
	for (i=1;i<=n;i++) mind[i][0]=i;
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			int p=mind[i][j-1],q=mind[i+(1<<(j-1))][j-1];
			if (dep[p]<dep[q]) mind[i][j]=p; else mind[i][j]=q;
		}
	}
}

int find(int l,int r) {
	int k=0;
	while ((1<<(k+1))<=(r-l+1)) k++;
	int p=mind[l][k],q=mind[r-(1<<k)+1][k];
	return dep[p]<dep[q]?a[p]:a[q];
}

int main() {
int cas;
scanf("%d",&cas);
while (cas--) {
	int n,q,i,j,x,y,z;
	scanf("%d%d",&n,&q);
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<n;i++) {
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	dfn=0;
	mem0(visit);
	dist[1]=0;
	dfs(1,0);
	init(dfn);
	for (i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		int p;
		if (f[x]>f[y]) p=find(f[y],f[x]); else p=find(f[x],f[y]);
		int ans=dist[x]+dist[y]-2*dist[p];
		printf("%d\n",ans);
	}
}
	return 0;
}

