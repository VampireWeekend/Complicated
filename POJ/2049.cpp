#include <cstdio>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
const int maxn=205;
int map[maxn][maxn],bx[maxn][maxn],by[maxn][maxn];
int dx,dy;

void dfs(int x,int y) {
	
}

int main() {
	int n,m,i,j,x,y,d,t;
	scanf("%d%d",&m,&n);
	while ((m!=-1)||(n!=-1)) {
		memset(map,-1,sizeof(map));
		memset(border,0,sizeof(border));
		for (i=1;i<=m;i++) {
			scanf("%d%d%d%d",&x,&y,&d,&t);
			if (d) {
				for (j=y;j<y+t;j++) border[x][j]=1;
			} else {
				for (j=x;j<x+t;j++) border[j][y]=1;
			}
		}
		for (i=1;i<=n;i++) {
			scanf("%d%d%d%d",&x,&y,&d);
			if (d) border[x][y]=2; else border[x][y]=2;
		}
		
	}
	return 0;
}
