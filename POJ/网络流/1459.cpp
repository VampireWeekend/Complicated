//网络流基础：多源点多汇点问题 
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=105;
int path[maxn],visit[maxn],flow[maxn][maxn],rflow[maxn];
int i,n,np,nc,m,sumf;
char c;

int bfs(int s,int t) {
	memset(visit,0,sizeof(visit));
	memset(path,-1,sizeof(path));
	memset(rflow,0,sizeof(rflow));
	queue<int> q;
	visit[s]=1;
	q.push(s);
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=0;i<=n+1;i++) {
	    	if (flow[now][i]>0&&!visit[i]) {
	    	    path[i]=now;
	    	    visit[i]=1;
	    	    if (now!=s) rflow[i]=min(rflow[now],flow[now][i]); 
				    else rflow[i]=flow[now][i];
	    	    if (i==t) return rflow[i];
	    	    q.push(i);
	    	}
	    }
    }
    return 0;
}

int EdmondsKarp(int s,int t) {
	int f,sum=0;
	while (f=bfs(s,t)) {
		int now=t;
		while (path[now]!=-1) {
			int pre=path[now];
			flow[pre][now]-=f;
			flow[now][pre]+=f;
			now=pre;
		}
		sum+=f;
	}
	return sum;
}

int main() {
	while (scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF) {
		int x,y,f;
		memset(flow,0,sizeof(flow));
		for (i=1;i<=m;i++) {
			cin >> c >> x >> c >> y >> c >> f;
			flow[x+1][y+1]=f;
		}
		for (i=1;i<=np;i++) {
			cin >> c >> x >> c >> f;
			flow[0][x+1]=f;
		}
		for (i=1;i<=nc;i++) {
			cin >> c >> x >> c >> f;
			flow[x+1][n+1]=f;
		}
		sumf=EdmondsKarp(0,n+1);
		cout << sumf << endl;
	}
	return 0;
}
