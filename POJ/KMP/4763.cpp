#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
int nxt[maxn];

int max(int a,int b) {
	if (a>b) return a; else return b;
}

void getnxt(int len) {
	nxt[0]=nxt[1]=0;
	int j=0;
	for (int i=1;i<len;i++) {
		while (s[i]!=s[j]&&j>0) j=nxt[j];
		if (s[i]==s[j]) j++;
		nxt[i+1]=j;
	}
}

int main() {
	int n,i,q;
	scanf("%d",&n);
	for (q=1;q<=n;q++) {
		scanf("%s",s);
		int len=strlen(s);
		getnxt(len);
		int ans=0;
		for (i=len-1;i>=2;i--) {
			int k=nxt[i];
			while (k>0) {
				if (k<=nxt[len]&&2*k<=i&&k+i<=len)
				    ans=max(ans,k);
				k=nxt[k];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
