//KMPÄ£°å 
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxm=10005;
const int maxn=1000005;
char s[maxn],k[maxm];
int next[maxm];

void buildnext(char s[]) {
	int len=strlen(s);
	int j=0;
	next[0]=next[1]=0;
	for (int i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=next[j];
		if (s[i]==s[j]) j++;
		next[i+1]=j;
	}
}

int main() {
	int n,i,ans,t,j;
	scanf("%d",&n);
	for (t=1;t<=n;t++) {
		scanf("%s",k);
		scanf("%s",s);
		int lenk=strlen(k),lens=strlen(s);
		ans=0;
		buildnext(k);
		j=0;
	    for (i=0;i<lens;i++) {
	    	while (j>0&&k[j]!=s[i]) 
	    	    j=next[j];
	    	if (k[j]==s[i]) j++;
	    	if (j==lenk) ans++;
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
