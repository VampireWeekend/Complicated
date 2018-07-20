#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cmath>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db eps=1e-6;
int head[maxn];
db x[maxn],y[maxn],z[maxn];
bool v[maxn];
int num;

struct node {
	int id;db dist;
	node(int id,db dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
		return dist>x.dist;
	}
};

db sqr(db x) {
	return x*x;
}

struct Edge {
	int from,to,pre;
	db dist,cost,d;
};
Edge edge[maxn*maxn];

void addedge(int from,int to,db dist,db cost) {
	edge[num].from=from;edge[num].to=to;edge[num].pre=head[from];
	edge[num].dist=dist;edge[num].cost=cost;
	head[from]=num++;
	edge[num].from=to;edge[num].to=from;edge[num].pre=head[to];
	edge[num].dist=dist;edge[num].cost=cost;
	head[to]=num++;
}

db Dinkelbach(int n) {
	db l,ans=0;
	int m=n*(n-1),cnt=0;
	int i,j;
	while (true) {
		l=ans;cnt++;
		priority_queue<node> pq;
		for (i=0;i<m;i++) {
			edge[i].d=edge[i].cost-l*edge[i].dist;
//			cout << i << ' ' << edge[i].d << endl;
			if (edge[i].from==1) {
				pq.push(node(i,edge[i].d));
	//			edge[i].t=edge[i^1].t=cnt;
			}
		}
		db s0,s1;
		s0=s1=0;
		mem0(v);
		v[1]=1;
		for (i=1;i<n;i++) {
			int now=pq.top().id;
			pq.pop();
			while (v[edge[now].from]&&v[edge[now].to]) {
				now=pq.top().id;
			    pq.pop();
			}
			int to=(v[edge[now].from]?edge[now].to:edge[now].from);
			v[edge[now].from]=v[edge[now].to]=1;
			s0+=edge[now].cost;s1+=edge[now].dist;
			for (j=head[to];j!=-1;j=edge[j].pre) {
				pq.push(node(j,edge[j].d));
			}
		}
		ans=s0/s1;
		if (fabs(ans-l)<eps) return ans;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	while (n) {
		num=0;
		memset(head,-1,sizeof(head));
		int i,j;
		for (i=1;i<=n;i++) {
			scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
			for (j=1;j<i;j++) {
				addedge(i,j,sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])),fabs(z[i]-z[j]));
			}
		}
		db ans=Dinkelbach(n);
		printf("%.3lf\n",ans);
		scanf("%d",&n);
	} 
	return 0;
}
