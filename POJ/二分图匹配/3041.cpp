#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=1005,maxk=10005;
int match[maxn],visit[maxn];
int n,k,i,ans,r,c;
vector<int> v[maxn];
// Hungarian二分匹配 dfs版本 
//最小顶点覆盖数=最大匹配数 
bool dfs(int now) {
	int size=v[now].end()-v[now].begin();
	int i,to;
	for (i=0;i<size;i++) {
		to=v[now][i];
		if (!visit[to]) {
			visit[to]=true;
			if (!match[to]||dfs(match[to])) {
				match[to]=now;
				match[now]=to;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> k;
	for (i=1;i<=k;i++) {
		cin >> r >> c;
		v[r].push_back(n+c);
		v[n+c].push_back(r);
	}
	ans=0; 
	memset(match,0,sizeof(match));
	for (i=1;i<=n;i++) {
		if (match[i]==0) {
			memset(visit,0,sizeof(visit));
			if (dfs(i)) ans++;
		}
	}
	cout << ans; 
	return 0;
}
