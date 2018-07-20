#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn=1000005,mod=10007;
int nxt[maxn],f[maxn];
char s[maxn];
int ans;

void buildnext(int len) {
	nxt[0]=nxt[1]=f[0]=f[1]=0;
	int i,j;
	j=0;
	for (i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=nxt[j];
		if (s[i]==s[j]) j++;
		nxt[i+1]=j;
		if (j!=0) f[i+1]=f[nxt[i+1]]+1; else f[i+1]=0;
		ans+=f[i+1];
		ans%=mod;
	}
}

int main() {
	int n,i,j,len;
	scanf("%d",&n);
	scanf("%s",s);
	len=strlen(s);
	ans=len;
	buildnext(len);
	ans%=mod;
	cout << ans;
	return 0;
}
