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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],size[maxn],ms[maxn],d[maxn];
int num=0,root=-1,rs=inf,sum,k,ans,cnt=0;
bool visit[maxn];
char s[maxn];

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

void getroot(int now,int fa) {
	size[now]=ms[now]=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) {
			getroot(to,now);
			size[now]+=size[to];
			ms[now]=max(ms[now],size[to]);
		}
	}
	size[now]++;
	ms[now]=max(ms[now],sum-size[now]);
	if (ms[now]<rs) root=now,rs=ms[now];
}

void dfs(int now,int fa,int dis) {
	d[++cnt]=dis;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) dfs(to,now,dis+edge[i].dist); 
	} 
}

int cal(int now,int fa,int dis) {
	cnt=0;
	dfs(now,0,dis);
	sort(d+1,d+cnt+1);
	int ssum=0,i,l=1,r=cnt;
	while (l<r) {
		if (d[l]+d[r]<=k) {
			ssum+=r-l;
			l++;
		} else r--;
	}
	return ssum;
}

void solve(int now) {
	visit[now]=1;
	ans+=cal(now,0,0); 
	
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) 
			ans-=cal(to,now,edge[i].dist); 
	}
	
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			root=-1,rs=inf;
			sum=size[to];
			getroot(to,0);
			solve(root);
		}
	}
}

int main() {
	int i,j,x,y,z,n;
	scanf("%d%d",&n,&k);
	while (n||k) {
		num=ans=0;
		memset(head,-1,sizeof(head));
		for (i=1;i<n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
		}
		sum=n;
		getroot(1,0);
		mem0(visit);
		solve(root);
		printf("%d\n",ans);
		scanf("%d%d",&n,&k);
	}
	return 0;
}
