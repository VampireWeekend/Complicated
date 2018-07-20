#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=100005;
char s[maxn],t[maxn];
int nxt[maxn],a[maxn];

void buildnxt(char s[]) {
	nxt[0]=nxt[1]=0;
	int j=0,i;
	int len=strlen(s);
	for (i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j]&&s[i]!='?'&&s[j]!='?') 
			j=nxt[j];
		if (s[i]==s[j]||s[i]=='?'||s[j]=='?') 
		    j++;
		nxt[i+1]=j;
	}
}

int main() {
	int i,ans,len1,len2,j;
	scanf("%s",s);	
	scanf("%s",t);
	buildnxt(t);
	len1=strlen(s);
	len2=strlen(t);
	j=ans=0;
	for (i=0;i<len1;i++) {
		while (j>0&&s[i]!=t[j]&&t[j]!='?'&&((s[i]+i-'a')%26!=(t[j]-'a')))
		    j=nxt[j];
		if (s[i]==t[j]||t[j]=='?'||((s[i]+i-'a')%26==(t[j]-'a'))) 
		    j++;
		if (j==len2) 
			a[++ans]=i-len2+1;
	}
	cout << ans << endl;
	for (i=1;i<=ans;i++) printf("%d\n",a[i]);
	return 0;
}
