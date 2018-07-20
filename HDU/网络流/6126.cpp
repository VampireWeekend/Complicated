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
const int maxn=55,maxk=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn][maxn];
int head[maxn*maxn],dist[maxn*maxn],current[maxn*maxn];
int num;

struct Edge {  
    int from,to,flow,pre;  
};  
Edge edge[maxk];  
  
void addedge(int from,int to,int flow) {  
    edge[num]=(Edge){from,to,flow,head[from]};  
    head[from]=num++;  
    edge[num]=(Edge){to,from,0,head[to]};  
    head[to]=num++;  
}  
  
bool bfs (int n) {  
    queue<int> q;  
    q.push(0);  
    memset(dist,-1,sizeof(dist));  
    dist[0]=0;  
    while (!q.empty()) {  
        int now=q.front();  
        q.pop();  
        for (int i=head[now];i!=-1;i=edge[i].pre) {  
            int to=edge[i].to;  
            if (dist[to]==-1&&edge[i].flow>0) {  
                dist[to]=dist[now]+1;  
                q.push(to);  
            }  
        }  
    }  
    return dist[n]!=-1;  
}  
  
int dfs(int now,int flow,int n) {  
    int f;  
    if (now==n) return flow;  
    for (int i=current[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        current[now]=i;  
        if (dist[now]+1==dist[to]&&edge[i].flow>0&&  
        (f=dfs(to,min(flow,edge[i].flow),n))) {  
            edge[i].flow-=f;  
            edge[i^1].flow+=f;  
            return f;  
        }  
    }  
    return 0;  
}  
  
int dinic(int n) {  
    int sum=0,f;  
    while (bfs(n)) {  
        memcpy(current,head,sizeof(head));  
        while (f=dfs(0,inf,n)) sum+=f;  
    }  
    return sum;  
}  

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,k,i,j,x,y,z;
		memset(head,-1,sizeof(head));
		num=0;
		scanf("%d%d%d",&n,&m,&k);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i][1]);
			addedge(0,(i-1)*m+1,1e7);
			for (j=2;j<=m;j++) {
				scanf("%d",&a[i][j]);
				addedge((i-1)*m+j-1,(i-1)*m+j,1000-a[i][j-1]);
			}
			addedge(i*m,n*m+1,1000-a[i][m]);
		}
		for (i=1;i<=k;i++) {
			scanf("%d%d%d",&x,&y,&z);
			for (j=max(z+1,1);j<=m&&j-z<=m;j++) {
				addedge((x-1)*m+j,(y-1)*m+j-z,1e7);
			}
			if (j-z>m&&j<=m)
				addedge((x-1)*m+j,n*m+1,1e7);
		}
		int ans=dinic(n*m+1);
		if (ans>1e7) printf("-1\n"); else printf("%d\n",n*1000-ans);
	} 
	return 0;
}
