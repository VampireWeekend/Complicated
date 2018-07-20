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
const int maxn=100005,maxk=63,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn];
ll c[maxn*4],x[maxn],v[maxn];
bool visit[maxn];
int num=0,cm=0;

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,ll dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void dfs(int now,ll k) {
	visit[now]=1;v[now]=k;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) dfs(to,k^edge[i].dist);
			else c[++cm]=k^edge[i].dist^v[to];
	}
}

bool linear_basis_insert(ll p) {
	for (int i=maxk;i>=0;i--) {
		if ((p>>i)%2==1) {
			if (!x[i]) {
				x[i]=p;
				for (int j=i-1;j>=0;j--) 
					if (x[j]&&((x[i]>>j)%2==1)) x[i]^=x[j];
                for (int j=i+1;j<=maxk;j++) 
					if ((x[j]>>i)%2==1) x[j]^=x[i];
				return true;
			} else p=p^x[i];
		}
	}
	return p!=0;
}

int main() {
	int n,m,i,j,z,y;
	ll d;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (i=1;i<=m;i++) {
		scanf("%d%d%lld",&z,&y,&d);
		addedge(z,y,d);
	}
	mem0(visit);
	dfs(1,0);
	mem0(x);
	for (i=1;i<=cm;i++) 
		linear_basis_insert(c[i]);
	ll ans=v[n];
	for (i=maxk;i>=0;i--) 
		if ((x[i]^ans)>ans) ans^=x[i];
	printf("%lld\n",ans);
	return 0;
}

