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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int dp[maxn][11];
int head[maxn];
bool visit[maxn];
int num,p;

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

void dfs(int now) {
	visit[now]=1;
	int i,j,k;
	for (i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to);
			for (k=p;k>=0;k--) {
				dp[now][k]+=dp[to][0]+2*edge[i].dist;
				for (j=1;j<=k;j++) {
					dp[now][k]=min(dp[now][k],
					dp[now][k-j]+dp[to][j]+j*edge[i].dist);
				}
		//		cout << dp[now][k] << endl;
			}
		}
	}
}

int main() {
	int n,s;
	while (scanf("%d%d%d",&n,&s,&p)!=EOF) {
		int i,x,y,d;
		num=0;
		memset(head,-1,sizeof(head));
		mem0(visit);mem0(dp);
		for (i=1;i<n;i++) {
			scanf("%d%d%d",&x,&y,&d);
			addedge(x,y,d);
		}
		dfs(s);
		printf("%d\n",dp[s][p]);
	}
	return 0;
}

