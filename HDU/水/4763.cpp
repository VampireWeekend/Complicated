#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int now[30],pre[30],pre2[30];

int main() {
	int n,i,j,k,q;
	scanf("%d",&n);
	for (q=1;q<=n;q++) {
		scanf("%s",s);
		memset(pre,-1,sizeof(pre));
		memset(pre2,-1,sizeof(pre2));
		int len=strlen(s),ans=0;
		for (i=0;i<len;i++) {
			int pos=s[i]-'a';
			pre2[pos]=pre[pos];pre[pos]=now[pos];now[pos]=i;
			if (pre2[pos]!=-1) 
				ans=max(ans,i-pre2[pos]-2);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
