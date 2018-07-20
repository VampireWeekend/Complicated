#include <cstdio>
#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
const int maxn=16005;
int color[maxn],dfn[maxn],num,flag;

vector<int> v[maxn];

bool dfs(int now) {
	if (color[now]==2) return false;
	if (color[now]==1) return true;
	color[now]=1;
	color[now^1]=2;
	dfn[++num]=now;
	int size=v[now].size();
	for (int i=0;i<size;i++) {
		int to=v[now][i];
		if (!dfs(to)) return false;
	}
	return true;
}

int main() {
	int n,m,i,j,x,y,a,b;
	while (scanf("%d%d",&n,&m)!=EOF) {
		for (i=1;i<=m;i++) {
			scanf("%d%d",&x,&y);
			x--;y--;
			v[x].push_back(y^1);
			v[y].push_back(x^1);
		}
		memset(color,0,sizeof(color));
		int flag=1;
		for (i=0;i<n;i++) {
			if (!color[i*2]) {
				num=0;
				if (!dfs(i*2)) {
					for (j=1;j<=num;j++) 
						color[dfn[j]]=color[dfn[j]^1]=0;
					if (!dfs(i*2+1)) {
				    	flag=0;
				    	break;
			    	}
				}
			}
		}
		if (flag) {
			for (i=0;i<n;i++) {
				if (color[i*2]==1) printf("%d\n",i*2+1); 
				    else printf("%d\n",i*2+2);
			}
		} else printf("NIE\n");
		for (i=0;i<n*2;i++) v[i].clear();
	}
	return 0;
}
