#include <cstdio>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
int a[maxn],rl[maxn];
char s[maxn],t[maxn];

int cmp(int *r,int a,int b,int l) {
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void build(int *r,int *sa,int n,int m) {
	int i,j,k,p,*x=wa,*y=wb,*t;
	for (i=0;i<m;i++) ws[i]=0;
	for (i=0;i<n;i++) ws[x[i]=r[i]]++;
	for (i=0;i<m;i++) ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
	for (j=1,p=1;p<n;j*=2,m=p) {
		for (p=0,i=n-j;i<n;i++)  y[p++]=i;
		for (i=0;i<n;i++)  if (sa[i]>=j) y[p++]=sa[i]-j;
		for (i=0;i<n;i++) wv[i]=x[y[i]];
		for (i=0;i<m;i++) ws[i]=0;
		for (i=0;i<n;i++) ws[wv[i]]++;
		for (i=1;i<m;i++) ws[i]+=ws[i-1];
		for (i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
		t=x;x=y;y=t;
		p=1;x[sa[0]]=0;
		for (i=1;i<n;i++) 
		    x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	for (i=1;i<n;i++) ranki[sa[i]]=i;
	k=0; 
	for (i=0;i<n-1;height[ranki[i++]]=k) {
		if (k) k--;
		for (j=sa[ranki[i]-1];r[i+k]==r[j+k];k++);
	}
}

void manacher(int len) {
	int i,maxright,pos;
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
	}
}

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		scanf("%s",t);
		int len=strlen(t),i;
		for (i=0;i<len;i++) {
			s[i*2]='#';
			s[i*2+1]=t[i];
			a[i*2+1]=t[i]-'a'+2;
			a[i*2]=1;
		}
		s[len*2]='#';s[len*2+1]='@';a[len*2]=1;a[len*2+1]=0;
		manacher(len*2+2);
		build(a,sa,len*2+2,30);
		int sum=0,MX=0;
		for (i=1;i<=len*2+1;i++) {
			MX=min(MX,height[i]);
			if (rl[sa[i]]<=MX) continue;
			sum+=(rl[sa[i]]-MX)/2;
			MX=rl[sa[i]];
		}
		printf("Case #%d: %d\n",cnt,sum);
	}
	return 0;
}

