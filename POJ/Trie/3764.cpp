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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int num;
int head[maxn];
ll a[maxn];
bool visit[maxn];

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,ll dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void dfs(int now,ll val) {
	visit[now]=1;
	a[now]=val;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			dfs(to,val^edge[i].dist);
	}
}

struct Tree{
	int l,r;
};
Tree tree[maxn*32];

void insert(int now,ll val,int depth) {
	if (depth==32) return;
	if ((val>>(31-depth))%2==1) {
		if (tree[now].l==-1) {
			tree[now].l=++num;
			tree[num].l=tree[num].r=-1;
		}	
		insert(tree[now].l,val,depth+1);
	} else {
		if (tree[now].r==-1) {
			tree[now].r=++num;
			tree[num].l=tree[num].r=-1;
		}
		insert(tree[now].r,val,depth+1);
	}
}

ll findxor(int now,ll val,int depth) {
	if (depth==32) return 0;
	if ((val>>(31-depth))%2==0) {
		if (tree[now].l!=-1)
		return findxor(tree[now].l,val,depth+1)+(1<<(31-depth));
		else  return findxor(tree[now].r,val,depth+1);
	} else {
		if (tree[now].r!=-1) 
		return findxor(tree[now].r,val,depth+1)+(1<<(31-depth));
		else return findxor(tree[now].l,val,depth+1);
	}
}

int main() {
	int n,i,t,x,y;
	ll ans,d;
while (scanf("%d",&n)!=EOF) {
	ans=num=0;memset(head,-1,sizeof(head));
	for (i=1;i<n;i++) {
		scanf("%d%d%lld",&x,&y,&d);
		addedge(x,y,d);
	}
	mem0(visit);
	dfs(0,0);
	tree[0].l=tree[0].r=-1;num=0;
	for (i=0;i<n;i++) 
		insert(0,a[i],0);
	for (i=0;i<n;i++) 
		ans=max(ans,findxor(0,a[i],0));
	printf("%lld\n",ans);
}
	return 0;
}

