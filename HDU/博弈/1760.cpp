#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=54;
char a[maxn][maxn];

int dfs(int n,int m) {
	bool visit[10000];
	memset(visit,0,sizeof(visit));
	int i,j,f;
	for (i=1;i<n;i++) {
		for (j=0;j<m-1;j++) {
			if (a[i][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j]=='0'&&a[i+1][j+1]=='0') {
				a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]='1';
				if ((f=dfs(n,m))==0) {
					a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]='0';
					return 1;
				}
				visit[f]=1;
				a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]='0';
			}
		}
	}
	for (i=0;;i++) {
		if (!visit[i])
		    return i;
	}
}

int main() {
	int n,m,i,j;
	while (scanf("%d%d",&n,&m)!=EOF) {
		for (i=1;i<=n;i++) {
			scanf("%s",a[i]);
		}
		if (dfs(n,m)) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
