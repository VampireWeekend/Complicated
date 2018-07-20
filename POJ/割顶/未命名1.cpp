//ͼ�ĸ 
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=103;
int n,ans,i,j,clock,pre[maxn],post[maxn],k,t;
bool cut[maxn];
vector<int> v[maxn];

void dfs(int now,int fa) {
	pre[now]=++clock;
	
}

int main() {
	scanf("%d",&n);
	while (n) {
		scanf("%d",&k);
		while (k){
			while (getchar()!='\n') {
				scanf("%d",&t);
				v[k].push_back(t);
				v[t].push_back(k);
			}
		}
		memset(pre,0,sizeof(pre));
		clock=0;
		
		for (i=1;i<=n;i++) v[i].clear();
		scanf("%d",&n);
	}
	return 0;
}
