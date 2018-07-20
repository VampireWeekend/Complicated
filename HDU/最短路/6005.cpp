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
const int maxn=8005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],dist[maxn];
bool visit[maxn];
int num,ans;
map<pair<int,int>,int> mp; 

struct Edge {
	int from,to,dist,pre;
};
Edge edge[maxn*2];

void addedge(int f,int t,int d) {
	edge[num].from=f;edge[num].to=t;edge[num].dist=d;
	edge[num].pre=head[f];head[f]=num++;
	edge[num].from=t;edge[num].to=f;edge[num].dist=d;
	edge[num].pre=head[t];head[t]=num++;
}

struct node {
	int id,dist;
	node(int id,int dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};

int dj(int n,int s,int t) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	visit[s]=1;
	for (j=head[s];j!=-1;j=edge[j].pre) 
		pq.push(node(j,edge[j].dist));
	meminf(dist);dist[s]=0;
	for (int k=1;k<n;k++) {
		if (pq.top().dist>ans) break;
		i=pq.top().id;
		int to=edge[i].to;
		if (visit[to]) continue;
		visit[to]=1;
		dist[to]=pq.top().dist;
		pq.pop();
		for (j=head[to];j!=-1;j=edge[j].pre) 
			if (!visit[edge[j].to]&&dist[to]+edge[j].dist<ans) 
				pq.push(node(j,dist[to]+edge[j].dist));
	}
	return dist[t];
}

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		int n,i,j,x,y,s,t,d,m=0;
		mp.clear();
		num=0;memset(head,-1,sizeof(head));
		scanf("%d",&n);
		ans=inf;
		for (i=1;i<=n;i++) {
			scanf("%d%d",&x,&y);
			s=mp[make_pair(x,y)];
			if (!s) s=mp[make_pair(x,y)]=++m;
			scanf("%d%d%d",&x,&y,&d);
			t=mp[make_pair(x,y)];
			if (!t) t=mp[make_pair(x,y)]=++m;
			addedge(s,t,d);
		}
		for (i=0;i<n;i++) {
			d=edge[i*2].dist;
			edge[i*2].dist=edge[i*2+1].dist=inf;
			int x=dj(m,edge[i*2].from,edge[i*2].to);
			ans=min(ans,x+d);
			edge[i*2].dist=edge[i*2+1].dist=d;
		}
		if (ans==inf) ans=0;
		printf("Case #%d: %d\n",cnt,ans);
	}
	return 0;
}

