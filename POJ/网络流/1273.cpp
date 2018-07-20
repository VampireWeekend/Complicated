//最大流EK算法 
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int maxn=205;
int path[maxn],rflow[maxn],flow[maxn][maxn];
bool visit[maxn];
int n,m,i;

int bfs(int s,int t) {
	memset(path,0,sizeof(path));
	memset(visit,0,sizeof(visit));
	memset(rflow,0,sizeof(rflow));
	queue<int> q;
	q.push(s);
	visit[s]=1;
	while (!q.empty()){
		int now=q.front();
		q.pop();
		for (int to=1;to<=n;to++) {
			if (!visit[to]&&flow[now][to]>0) {
				visit[to]=1;
				path[to]=now;
				if (now==s) rflow[to]=flow[now][to]; 
				    else rflow[to]=min(rflow[now],flow[now][to]);
				if (to==t) return rflow[to];
				q.push(to);
			}
		}
	}
	return 0;
}

int EdmondsKarp(int s,int t) {
	int f=0,fn;
	while (fn=bfs(s,t)) {
		int now=t;
		while (path[now]!=0) {
			int pre=path[now];
			flow[pre][now]-=fn;
			flow[now][pre]+=fn;
			now=pre;
		}
		f+=fn;
	}
	return f;
}

int main() {
	while (scanf("%d%d",&m,&n)!=EOF) {
	   	memset(flow,0,sizeof(flow));
    	int x,y,f;
    	for (i=1;i<=m;i++) {
    		scanf("%d%d%d",&x,&y,&f);
    		flow[x][y]+=f;
    	}
    	int ans=EdmondsKarp(1,n);
    	cout << ans << endl;
	}
	return 0;
}
