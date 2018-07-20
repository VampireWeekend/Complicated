#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int n,m,f[100001],i,son,father,k1,k2,l[100001],stack[100001];

void dfs(int now)
{
	int top=0;
	int k=now;
	if (f[k]==0) return;
	while (1) {		
		if ((f[k]==0)||(l[k]!=0)) break; else {
			top++;
			stack[top]=k;
		}
		k=f[k];
	}
	int step;
	if (f[k]==0) step=0; else step=l[k];
	while (top>=1) {
		step++;
		l[stack[top]]=step;
		top--;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	while ((n!=0)&&(m!=0)) {
		memset(l,0,sizeof(l));
		memset(f,0,sizeof(f));
		for (i=1;i<=n-1;i++) {
			scanf("%d%d",&father,&son);
			f[son]=father;
		}
		for (i=1;i<=m;i++){
			scanf("%d%d",&k1,&k2);	
			if (l[k1]==0) dfs(k1);
			if (l[k2]==0) dfs(k2);			
			if (l[k1]<=l[k2]) printf("lxh\n"); else printf("pfz\n"); 
		}
		scanf("%d%d",&n,&m);
	}
}
