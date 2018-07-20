//×Ö·û´®hash
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=16000005;
bool hash[maxn];
char s[maxn];
int a[260];
int ans;

int main() {
	int n,nc,i,j,sum,k;
	scanf("%d%d",&n,&nc);
	scanf("%s",&s);
	memset(hash,0,sizeof(hash));
	memset(a,0,sizeof(a));
	int len=strlen(s);
	ans=k=0;
	for (i=0;i<len;i++) {
		if (!a[s[i]]) {
			a[s[i]]=k++;
		}
		if (k==nc) break;
	} 
	for (i=0;i<=len-n;i++) {
		sum=0;
		for (j=0;j<n;j++) {
			sum*=nc;
			sum+=a[s[i+j]];
		}
		if (!hash[sum]) {
			ans++;
			hash[sum]=1;
		}
	}
	cout << ans;
	return 0;
}
