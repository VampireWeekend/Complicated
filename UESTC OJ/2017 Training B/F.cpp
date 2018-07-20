#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=100005,maxk=2000005,inf=0x3f3f3f3f;
int dist[maxn],t[maxn],head[maxn],num,safe[maxn],mark[maxk];
struct node {
	int id,dist;
	node(int id,int dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;
struct Edge {
	int from,to,dist,pre;
};
Edge edge[maxk];

void addedge(int f,int t,int d) {
	edge[num].from=f;edge[num].to=t;edge[num].dist=d;
	edge[num].pre=head[f];head[f]=num++;
	edge[num].from=t;edge[num].to=f;edge[num].dist=d;
	edge[num].pre=head[t];head[t]=num++;
}

int dj(int k) {
	int ans=inf,j,i;
	while (!pq.empty()) {
		i=pq.top().id;
		int from,to;
		from=edge[i].from;
		to=edge[i].to;
		pq.pop();
		if (t[to]==k&&edge[i].dist+dist[from]<dist[to]) {
			dist[to]=edge[i].dist+dist[from];
				for (j=head[to];j!=-1;j=edge[j].pre) {
		        	if (!mark[j]) {
		        		if (edge[j].from==to)
						    pq.push(node(j,edge[j].dist+dist[to]));
				        else 
						    pq.push(node(j^1,edge[j].dist+dist[to]));
		            	mark[j]=mark[j^1]=1;
		         	}
	        	}
		} else t[to]++;
	}
	return dist[0];
}

int main() {
	int n,m,k,i,j,x,y,w,d;
	num=0;
	memset(head,-1,sizeof(head));
	memset(t,0,sizeof(t));
	memset(mark,0,sizeof(mark));
	memset(dist,0x3f,sizeof(dist));
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
	}
	for (i=1;i<=k;i++) {
		scanf("%d",&safe[i]);
		t[safe[i]]=d;
		dist[safe[i]]=0;
		for (j=head[safe[i]];j!=-1;j=edge[j].pre) {
			if (!mark[j]) {
				if (edge[j].from==safe[i]) pq.push(node(j,edge[j].dist));
				    else pq.push(node(j^1,edge[j].dist));
		    	mark[j]=mark[j^1]=1;
			}
		}
	}
	int ans=dj(d);
	if (ans==inf) cout << -1; else printf("%d\n",ans);
	return 0;
}
