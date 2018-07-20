#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1005,maxm=1000005;
int head[maxn],num,f[maxn];
struct Edge{
	int dist,from,to,pre;
};
Edge edge[maxm];

void addedge(int s,int t,int d) {
	Edge e;
	e.from=s;e.to=t;e.dist=d;e.pre=head[s];
	edge[num]=e;head[s]=num++;
}

bool cmp(Edge a,Edge b) {
	return a.dist<b.dist;
}

int find (int now) {
	if (f[now]==now) return now; else {
		f[now]=find(f[now]);
		return f[now];
	}
}

int kruskal(int n) {
	int ans=0,cnt=0,i;
	for (i=0;i<=n;i++) f[i]=i;
	for (i=0;i<num;i++) {
		int fa=find(edge[i].from);
		int fb=find(edge[i].to);
		if (fa!=fb) {
			cnt++;
			ans+=edge[i].dist;
			if (cnt==n) return ans;
			f[fa]=fb;
		}
	}
	return 0;
}

int main() {
	int n,i,j,x;
	scanf("%d",&n);
	num=0;
	for (i=1;i<=n;i++) {
		for (j=i;j<=n;j++) {
			scanf("%d",&x);
			addedge(i-1,j,x);
		}
	}
	sort(edge,edge+num,cmp);
	int ans=kruskal(n);
	printf("%d",ans);
	return 0;
}
