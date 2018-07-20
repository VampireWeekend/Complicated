#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=200005;
vector<int> x[maxn],y[maxn],v[maxn];
int q[maxn];
int color[maxn];

void dfs(int s,int c) {
	int i,k,j;
	color[s]=c;
	int top=1,tail=0;
    q[1]=s;
    k=c^1;
	while (top>tail) {
		int num=top;
		for (j=tail+1;j<=num;j++) {
			int p=q[j];
			for (i=0;i<v[p].size();i++) {
	        	if (color[v[p][i]]==-1) {
	        		color[v[p][i]]=k;
	        		q[++top]=v[p][i];
	        	}
        	}
		}
		tail=num;
		k=k^1;
	}
}

int main() {
	int n,i,a,b;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&a,&b);
		if (x[a].size()%2) {
			v[i].push_back(x[a][x[a].size()-1]);
			v[x[a][x[a].size()-1]].push_back(i);
		}
		if (y[b].size()%2) {
			v[i].push_back(y[b][y[b].size()-1]);
			v[y[b][y[b].size()-1]].push_back(i);
		}
		x[a].push_back(i);
		y[b].push_back(i);
	}
	memset(color,-1,sizeof(color));
	for (i=1;i<=n;i++) 
		if (color[i]==-1) dfs(i,0);
	for (i=1;i<=n;i++) 
		if (color[i]==1) printf("r"); else printf("b");
	return 0;
}
