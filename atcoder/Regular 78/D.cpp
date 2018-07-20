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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int depth[maxn],visit[maxn],head[maxn],son[maxn];
bool connect[maxn];
int num;
int b,w,n;

struct Edge{
	int to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num].to=to;
	edge[num].pre=head[from];
	head[from]=num++;
	edge[num].to=from;
	edge[num].pre=head[to];
	head[to]=num++;
}

void dfs(int now,int step) {
	visit[now]=1;
	depth[now]=step;
	son[now]=1;
	if (now==n) connect[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,step+1);
			son[now]+=son[to];
			connect[now]=connect[now]|connect[to];
		}
	}
}

void dfs2(int now) {
	visit[now]=1;
	bool IsBlack;
	int p;
	if (depth[now]<=depth[n]/2) IsBlack=1; else IsBlack=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&connect[to]) {
			dfs2(to);
			p=to;
		}
	}
	if (now!=n&&now!=1) 
		if (IsBlack) {
			b+=son[now]-son[p];
		} else w+=son[now]-son[p];
}

int main() {
	int i,j,k,x,y;
	mem0(visit);
	mem0(son);
	mem0(connect);
	num=0;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0);
	int r;
	for (int i=head[1];i!=-1;i=edge[i].pre) {
		if (connect[edge[i].to]) {
			r=edge[i].to;
			break;
		}
	}
	b=n-son[r];
	w=son[n];
	mem0(visit);
	dfs2(1);
	if (b>w) printf("Fennec"); else printf("Snuke");
	return 0;
}
