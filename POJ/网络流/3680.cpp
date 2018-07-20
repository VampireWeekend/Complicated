//带有负权边的最小费用最大流 
//勿用vector!太慢 
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <algorithm> 
using namespace std;
const int maxn=450,maxk=3000;
const int inf=0x3f3f3f3f;
struct Edge {
	int from,to,cost,flow,pre;
};
Edge edge[maxk];
int rflow[maxn],dist[maxn],path[maxn],point[maxn],a[maxn],b[maxn],w[maxn];
int mark[100005],head[maxn];
bool inque[maxn];
int num;

bool cmp(int a,int b) {
	return a<b;
}

void addedge(int s,int t,int c,int f) {
	Edge e;
	e.from=s;e.to=t;e.cost=c;e.flow=f;e.pre=head[s];
	edge[num]=e;head[s]=num++;
	e.from=t;e.to=s;e.cost=-c;e.flow=0;e.pre=head[t];
	edge[num]=e;head[t]=num++;
}

int spfa(int s,int t) {
	memset(dist,0x3f,sizeof(dist));
	memset(inque,0,sizeof(inque));
	deque<int> q;
	int i;
	q.push_back(s);
	dist[s]=0;
	inque[s]=1;
	path[s]=-1;
	while (!q.empty()) {
		int now=q.front();
		inque[now]=0;
		q.pop_front();
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int k=i;
			int to=edge[i].to;
			if (edge[k].flow>0&&dist[now]+edge[k].cost<dist[to]) {
				if (now==s) rflow[to]=edge[k].flow; 
				    else rflow[to]=min(rflow[now],edge[k].flow);
				dist[to]=dist[now]+edge[k].cost;
				path[to]=k;
				if (!inque[to]) {
					inque[to]=1;
					//small label first
					if (!q.empty()) {
					    if (dist[to]<dist[q.front()]) q.push_front(to); 
						    else q.push_back(to);
					} else q.push_back(to);
			 	}	
			}
		}
	}
	if (dist[t]==inf) return 0; else return -dist[t];
}

int mincostmaxflow(int s,int t) {
	int sum=0,f,i;
	while (f=spfa(s,t)) {
		sum+=f;
		for (i=path[t];i!=-1;i=path[edge[i].from]) {
			edge[i].flow-=rflow[t];
			edge[i^1].flow+=rflow[t];
		}
	}
	return sum;
}

int main() {
	int t,i,q,k,nump,n;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		nump=num=0;
		scanf("%d%d",&n,&k);
		memset(mark,0,sizeof(mark));
		for (i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i],&b[i],&w[i]);
			if (!mark[a[i]]) {
				mark[a[i]]=1;
				point[++nump]=a[i];
			}
			if (!mark[b[i]]) {
				mark[b[i]]=1;
				point[++nump]=b[i];
			}
			head[2*i]=head[2*i-1]=-1;
		}
		head[0]=head[2*n+1]=-1;
		sort(point+1,point+nump+1,cmp);
		for (i=1;i<=nump;i++) {
			mark[point[i]]=i;
			if (i!=1) addedge(i-1,i,0,inf);
		}
		addedge(0,1,0,k);
		addedge(nump,nump+1,0,k);
		for (i=1;i<=n;i++) {
			addedge(mark[a[i]],mark[b[i]],-w[i],1);
		}
	/*	for (i=0;i<num;i++) {
	  		cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;
	  	}*/
		int ans=mincostmaxflow(0,nump+1);
		printf("%d\n",ans);
	}
	return 0;
}
