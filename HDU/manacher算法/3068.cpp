//manacher
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=400005;
char a[maxn],s[maxn];
int rl[maxn],ans;

void manacher(int len) {
	int i,maxright,pos;
	ans=0;
	maxright=pos=0;
	for (i=0;i<len;i++) {
		if (i<=maxright) {
			rl[i]=min(rl[2*pos-i],maxright-i);
		} else rl[i]=1;
		while (i-rl[i]>=0&&i+rl[i]<len&&s[i-rl[i]]==s[i+rl[i]])
		    rl[i]++;
		if (i+rl[i]-1>maxright) {
			maxright=i+rl[i]-1;
			pos=i;
		} 
		ans=max(ans,rl[i]);
	}
}

int main() {
	int i,j,n,len;
	while (scanf("%s",a)!=EOF) {
		len=strlen(a);
		s[0]='#';
		for (i=0;i<len;i++) {
			s[i*2+1]=a[i];
			s[i*2+2]='#';
		}
		len*=2;
		len++;
		manacher(len);
		printf("%d\n",ans-1);
	}
	return 0;
}
