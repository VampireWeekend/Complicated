#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=1000500;
const ll inf=1e15;
int n,m,num,nump;
ll dist[maxn],c[maxn];
int a[maxn],b[maxn],p[maxn],r[1<<21],head[maxn];
struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn];
bool inque[1<<21];
char aa[25],bb[25];

bool cmp(int x,int y) {
	return x<y;
}

int convert(string s,int len){
	int v=0,count=1,i;
	for (i=len-1;i>=0;i--) {
		v+=(s[i]-'0')*count;
		count*=2;
	}
	return v;
}

void addedge(int f,int t,ll d) {
	edge[++num].from=f;
	edge[num].to=t;
	edge[num].dist=d;
	edge[num].pre=head[f];
	head[f]=num;
}

ll spfa(int s,int des){
	int i;
    memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
	inque[1]=1;
	queue<int> q;
	q.push(1);
	dist[1]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;      //...............
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[edge[i].from]+edge[i].dist<dist[to]) {
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
				dist[to]=dist[edge[i].from]+edge[i].dist;
			}
		}
	}
	return dist[des];
}

int main() {
	memset(inque,0,sizeof(inque));
	memset(head,-1,sizeof(head));
	int i;
	nump=0;
	num=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
	    scanf("%s%s%lld",aa,bb,&c[i]);
		a[i]=convert(aa,n);
		b[i]=convert(bb,n);
	//	a[i]=i-1;b[i]=i;c[i]=1e9;
		if (!inque[a[i]]) {
			inque[a[i]]=1;
			p[++nump]=a[i];
		}
		if (!inque[b[i]]) {
			inque[b[i]]=1;
			p[++nump]=b[i];
		}
	}
	sort(p+1,p+nump+1,cmp);
	if ((p[nump]!=((1<<n)-1))||(p[1]!=0)) {
		cout << -1;
		return 0;
	}
	for (i=1;i<=nump;i++) 
		r[p[i]]=i;
	for (i=1;i<=m;i++) 
		addedge(r[a[i]],r[b[i]],c[i]);
	ll ans=spfa(1,nump);
	if (ans==inf) cout << -1; else printf("%lld",ans);
	return 0;
}
/*
3 5
000 110 2
000 010 4
000 101 2
110 111 41
000 111 80
*/
