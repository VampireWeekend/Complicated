//无向图最小割SW Algorithm 
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
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
const int maxn=3005,maxk=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],f[maxn],val[maxn],link[maxn];
int num,s,t,n,m;
bool visit[maxn];

struct node {
	int id,dist;
	node(int id,int dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist<x.dist;
	}
};

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxk*2];

void addedge(int from,int to,ll dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

int find(int x) {
	if (f[x]==x) return x; else {
		f[x]=find(f[x]);
		return f[x];
	}
}

ll kruskal(int n) {
	mem0(visit);mem0(val);
	priority_queue<node> pq;
	t=1;
	int cas=n-1;
	while (cas--) {
		visit[t]=1;s=t;
		int now,i;
		for (now=s;now;now=link[now]) {
			for (i=head[now];i!=-1;i=edge[i].pre) {
				int to=find(edge[i].to);
				if (!visit[to]) {
					val[to]+=edge[i].dist;
					pq.push(node(to,val[to]));
				}
			}
		}
		t=0;
		while (t==0) {
			if (pq.empty()) return 0;
			node now=pq.top();
			pq.pop();
			if (val[now.id]==now.dist) t=now.id;
		}
	}
	return val[t];
}

ll SW() {
	ll ans=llinf;
	int i;
	mem0(link);
	for (i=1;i<=n;i++) f[i]=i;
	for (i=n;i>1;i--) {
		ans=min(ans,kruskal(i));
		if (ans==0) break;
		while (link[s]) s=link[s];
		link[s]=t;
		f[t]=s;
	}
	return ans;
}

int main() {
    int i,x,y;
    ll d;
    while (scanf("%d%d",&n,&m)!=EOF) {
        num=0;
        memset(head,-1,sizeof(head));
        for (i=1;i<=m;i++) {
            scanf("%d%d%lld",&x,&y,&d);
            addedge(x,y,d); 
        }
        ll ans=SW();
        printf("%lld\n",ans);
    }
    return 0;
}
