//最小费用最大流 
//沿着关于可行流 f 的增广链μ，增加一个单位运量时，
//所增加的总费用是μ上所有前向弧的费用之和减去所有后向弧的费用之和
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=5005;
int n,m,i,j,nr,k,h[maxn][2],p[maxn][2],path[maxn],rflow[maxn],inque[maxn],dist[maxn];
string s;
struct Edge {
	int from,to,cost,flow;
};
vector<Edge> edge;
vector<int> v[maxn];

void addedge(int s,int t,int cost,int flow) {
	Edge e;
	e.from=s;
	e.to=t;
	e.cost=cost;
	e.flow=flow;
	edge.push_back(e);
	v[s].push_back(edge.size()-1);
	e.from=t;
	e.to=s;
	e.cost=-cost;
	e.flow=0;
	edge.push_back(e);
	v[t].push_back(edge.size()-1);
}

int spfa(int s,int t) {
	memset(inque,0,sizeof(inque));
	memset(path,-1,sizeof(path));
	memset(rflow,-1,sizeof(rflow));
	queue<int> q;
    q.push(s);
    inque[s]=1;
    int i;
    for (i=0;i<=2*n+1;i++) dist[i]=1<<30;
    dist[s]=0;
    rflow[s]=1<<30;
    while (!q.empty()) {
    	int now=q.front();
  //  	cout << now << endl;
    	q.pop();
    	inque[now]=0;
    	int s=v[now].size();
    	for (i=0;i<s;i++) {
    		int to=edge[v[now][i]].to;
    		int k=v[now][i];
    		if (edge[k].flow>0&&dist[now]+edge[k].cost<dist[to]) {
    			dist[to]=dist[now]+edge[k].cost;
    			path[to]=k;
    			rflow[to]=min(rflow[now],edge[k].flow);
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
    		}
    	}
    }
    if (dist[t]==1<<30) return 0; else return dist[t];
}

int mincostmaxflow(int s,int t) {
	int f,sum=0,now;
//	int tt=0;
	while (f=spfa(s,t)) {
		now=path[t];
//		cout << now << endl;
		while (now!=-1) {
			i=now;
//			cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;   
			edge[now].flow-=f;
			edge[now^1].flow+=f;
			now=path[edge[now].from];
//			cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;
		}
//		tt++;
//		cout << tt << endl; 	
		sum+=f;
	}
	return sum;
}

int main (){
	scanf("%d%d",&nr,&m);
	while (nr&&m) {
		int top1=0,top2=0;
	  	for (i=1;i<=nr;i++) {
	  		cin >> s;
	  	    for (j=0;j<m;j++) {
	  	    	if (s[j]=='m') {
	  	    		h[++top1][0]=i;
	  	    		h[top1][1]=j;
	  	    	} else if (s[j]=='H'){
	  	    		p[++top2][0]=i;
	  	    		p[top2][1]=j;
	  	    	}
	  	    }	
	  	}
	  	n=top1;
	  	for (i=1;i<=n;i++) {
	  		addedge(0,i,0,1);
	  		addedge(i+n,2*n+1,0,1);
	  		for (j=1;j<=n;j++) {
	  			addedge(i,j+n,abs(h[i][0]-p[j][0])+abs(h[i][1]-p[j][1]),1);
	  		}
	  	}	  	
	/*  	cout << edge.size();
	  	for (i=0;i<edge.size();i++) {
	  		cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;
	  	}*/
	  	int ans;
	  	ans=mincostmaxflow(0,2*n+1);
	  	cout << ans << endl;
	  	for (i=0;i<=2*n+1;i++) v[i].clear();
	  	scanf("%d%d",&nr,&m);
	  	edge.clear();
	}
	return 0;
} 
