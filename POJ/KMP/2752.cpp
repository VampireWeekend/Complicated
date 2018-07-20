#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn=400005,mod=10007;
int nxt[maxn],stack[maxn];
char s[maxn];
int ans;

void buildnext(int len) {
	nxt[0]=nxt[1]=0;
	int i,j;
	j=0;
	for (i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=nxt[j];
		if (s[i]==s[j]) j++;
		nxt[i+1]=j;
	}
}

int main() {
	int n,len,top,k;
	while (scanf("%s",s)!=EOF) {
		len=strlen(s);
		buildnext(len);
		k=nxt[len];
		top=1;
		stack[1]=len;
		while (k!=0) {
			stack[++top]=k;
			k=nxt[k];
		}
		while (top>0) {
			printf("%d ",stack[top]);
			top--;
		}
		printf("\n");
	}
	return 0;
}
