//无向图最小割SW Algorithm 
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
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
const int maxn=505,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int mp[maxn][maxn],dist[maxn];
int num,s,t,mcut;
bool visit[maxn],com[maxn];

void prim(int n) {
	mem0(visit);
	mem0(dist);
	int i,j,to;
	s=t=-1;
	for (i=1;i<=n;i++) {
		int m=-1;
		for (j=1;j<=n;j++) {
			if (!com[j]&&!visit[j]&&dist[j]>m) {
				m=dist[j];
				to=j;
			}
		}
		if (t==to) return;
		s=t;t=to;
		visit[to]=1;
		mcut=m;
		for (j=1;j<=n;j++) {
			if (!com[j]&&!visit[j]) {
				dist[j]+=mp[to][j];
			}
		}
	}
}

int SW(int n) {
	int i,j,cas=n-1,ans=inf;
	mem0(com);
	while (cas--) {
		prim(n);
		ans=min(ans,mcut);
		if (ans==0) return 0;
		com[t]=1;
		for (j=1;j<=n;j++) {
			if (!com[j]) {
				mp[s][j]+=mp[t][j];
				mp[j][s]+=mp[j][t];
			}
		}
	}
	return ans;
}

int main() {
	int n,m,i,x,y,d;
	while (scanf("%d%d",&n,&m)!=EOF) {
		num=0;
		mem0(mp);
		for (i=1;i<=m;i++) {
			scanf("%d%d%d",&x,&y,&d);
			mp[x+1][y+1]+=d;
			mp[y+1][x+1]+=d;
		}
		int ans=SW(n);
		printf("%d\n",ans);
	}
	return 0;
}
