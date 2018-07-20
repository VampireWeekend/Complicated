//ͼ�ĸ 
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=103;
int n,ans,i,j,clock,pre[maxn],low[maxn],k,t;
bool cut[maxn],a[maxn][maxn];
vector<int> v[maxn];

int min(int a,int b) {
    if (a<b) return a; else return b;	
}

int dfs(int now,int fa) {
	low[now]=pre[now]=++clock;
	int size=v[now].size();
	int child=0;
	for (int i=0;i<size;i++) {
		int to=v[now][i];
		if (!pre[to]) {
			int l=dfs(to,now);
			child++;
			low[now]=min(low[now],l);
			if (l>=pre[now]) cut[now]=1;
		} else if (pre[to]<pre[now]&&to!=fa) {
			low[now]=min(low[now],pre[to]);
		}
	}
	if (now==1) {
		if (child>1) cut[now]=1; else cut[now]=0;
	} 
	return low[now];
}

int main() {
	scanf("%d",&n);
	while (n) {
		memset(a,0,sizeof(a));
		scanf("%d",&k);
		while (k){
			while (getchar()!='\n') {
				scanf("%d",&t);
				if (!a[k][t]) {
					v[k].push_back(t);
			    	v[t].push_back(k);
				    a[k][t]=a[t][k]=1;
				}
			}
			scanf("%d",&k);
		}
		memset(pre,0,sizeof(pre));
		memset(cut,0,sizeof(cut));
		memset(low,0,sizeof(low));
		clock=0;
		int l=dfs(1,0);
		ans=0;
		for (i=1;i<=n;i++) if (cut[i]) ans++;
		cout << ans << endl;
		for (i=1;i<=n;i++) v[i].clear();
		scanf("%d",&n);
	}
	return 0;
}
/*
6
1 3 5
3 4
5 2 6
2 5 6
0
0
*/
