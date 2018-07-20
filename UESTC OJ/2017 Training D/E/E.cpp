//manacher
#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=4000005;
char a[maxn],s[maxn];
int rl[maxn],sum[maxn];
ll ans;
queue<int> q;

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
		if (rl[i]==i+1) q.push(i);
	}
}

int main() {
	int i,j,n,len;
	while (scanf("%s",a)!=EOF) {
		len=strlen(a);
		s[0]='#';
		memset(sum,0,sizeof(sum));
		for (i=0;i<len;i++) {
			s[i*2+1]=a[i];
			s[i*2+2]='#';
		}
		len*=2;
		len++;
		manacher(len);
		q.pop();
		while (!q.empty()) {
			int now=q.front();
			int l=now-(now+1)/2,r=now+(now+1)/2;
			sum[now]=sum[l]+1;
			ans+=sum[now];
			q.pop(); 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
