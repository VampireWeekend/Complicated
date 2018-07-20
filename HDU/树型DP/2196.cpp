//Ê÷ÐÍDP 
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=10005;
typedef long long ll;
ll up[maxn],max1[maxn],max2[maxn];
int visit[maxn],maxi[maxn];
vector<int> son[maxn]; 
vector<ll> dist[maxn]; 

ll cmp(ll a,ll b) {
	if (a>b) return a; else return b;
}

void dfs(int now) {
	visit[now]=1;
	max1[now]=0;max2[now]=0;maxi[now]=0;
	int size=son[now].end()-son[now].begin();
	for (int i=0;i<size;i++) {
		int node=son[now][i];
		if (!visit[node]) {
			dfs(node);
			if (max1[node]+dist[now][i]>max1[now]) {
				max2[now]=max1[now];
				max1[now]=max1[node]+dist[now][i];
				maxi[now]=node;
			} else if (max1[node]+dist[now][i]>max2[now]) {
				max2[now]=max1[node]+dist[now][i];
			} 
		} 
	}
}

void dfs2(int now) {
	visit[now]=1;
	int size=son[now].end()-son[now].begin();
	for (int i=0;i<size;i++) {
		int node=son[now][i];
		if (!visit[node]) {
			if (maxi[now]!=node) up[node]=cmp(up[now],max1[now])+dist[now][i]; else
			    up[node]=cmp(max2[now],up[now])+dist[now][i];
			dfs2(node);
		}
	}
}

int main() {
	int n,i;
	ll x,y;
while (scanf("%d",&n)!=EOF) {
	memset(visit,0,sizeof(visit));
	for (i=2;i<=n;i++) {
		cin >> x >> y;
		son[i].push_back(x);
		son[x].push_back(i);
		dist[i].push_back(y);
		dist[x].push_back(y);
	}	
	dfs(1);
	memset(visit,0,sizeof(visit));
	up[1]=0;
	dfs2(1);
	for (i=1;i<=n;i++) {
		cout << cmp(max1[i],up[i]) << endl;
	}
	for (i=1;i<=n;i++) {
		son[i].clear();
	    dist[i].clear();
	}
}
	return 0;
}
