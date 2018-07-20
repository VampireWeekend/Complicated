//²î·ÖÔ¼Êø 
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=100005,maxk=1000005;
int dist[maxn],num;
int inque[maxn],head[maxn];
struct Edge{
	int from,to,dist,pre;
};
Edge edge[maxk];

void addedge(int f,int t,int d) {
	edge[++num].from=f;
	edge[num].to=t;
	edge[num].dist=d;
	edge[num].pre=head[f];
	head[f]=num;
}

int spfa(int s,int des) {
	int i;
	memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	inque[1]=1;
	int t[maxn],top=1;
	t[top]=1;
	while (top>0) {
		int now=t[top];
		top--;
		inque[now]=0;
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[now]+edge[i].dist<dist[to]) {
				if (!inque[to]) {
					inque[to]=1;
					t[++top]=to;
				}
				dist[to]=dist[now]+edge[i].dist;
			}
		}
	}
    return dist[des];
}

int main() {
	int n,m,i,x,y,b;
    scanf("%d%d",&n,&m);
    num=0;
    for (i=1;i<=n;i++) head[i]=-1;
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&b);
		addedge(y,x,b);
	}
	int ans=spfa(1,n);
	printf("%d",ans);
	return 0;
}
