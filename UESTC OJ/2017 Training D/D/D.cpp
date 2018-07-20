#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
int nxt[maxn],ans;

int buildnxt(int len) {
	nxt[0]=nxt[1]=0;
	int i,j;
	j=0;
	for (i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=nxt[j];
		if (s[i]==s[j]) j++;
		nxt[i+1]=j;
	}
	return len-nxt[len];
}

int main() {
	scanf("%s",s);
	int len=strlen(s);
	cout << buildnxt(len);
	return 0;
}
