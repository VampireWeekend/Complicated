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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int dist[maxn],head[maxn];
int num;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j,x,y,s;
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		memset(dist,-1,sizeof(dist));
		num=0;
		for (i=1;i<=m;i++) {
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		scanf("%d",&s);
		set<int> st,pt;
		for (i=1;i<=n;i++) {
			if (i!=s) st.insert(i);
		}
		dist[s]=0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int now=q.front();
			q.pop();
			pt.clear();
			for (i=head[now];i!=-1;i=edge[i].pre) {
				if (dist[edge[i].to]==-1) {
					st.erase(edge[i].to); pt.insert(edge[i].to);
				}
			}
			set<int>::iterator iter;
			for (iter=st.begin();iter!=st.end();iter++) {
				dist[*iter]=dist[now]+1;
				q.push(*iter);
			}
			st.swap(pt);
		}
		for (i=1;i<=n;i++) {
			if (i!=s) 
			    if (dist[i]!=inf) printf("%d",dist[i]); else printf("-1");
			if (i!=n&&i!=s) printf(" ");
		}
		printf("\n");
	}
	return 0;
}

