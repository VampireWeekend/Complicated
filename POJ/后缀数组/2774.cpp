#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=200005;
typedef long long ll;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn];
int ranki[maxn],height[maxn],mn[maxn][20];
int s[maxn];
char a[maxn];

int cmp(int *r,int a,int b,int l) {
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void build(int *r,int *sa,int n,int m) {
	int i,j,k,p,*x=wa,*y=wb,*t;
	
	for (i=0;i<m;i++) ws[i]=0;
	for (i=0;i<n;i++) ws[x[i]=r[i]]++;
	for (i=0;i<m;i++) ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--) 
	    sa[--ws[x[i]]]=i;

	for (j=1,p=1;p<n;j*=2,m=p) {
		for (p=0,i=n-j;i<n;i++) 
		    y[p++]=i;
		for (i=0;i<n;i++) 
		    if (sa[i]>=j) y[p++]=sa[i]-j;

		for (i=0;i<n;i++) 
		    wv[i]=x[y[i]];
		for (i=0;i<m;i++) ws[i]=0;
		for (i=0;i<n;i++) 
		    ws[wv[i]]++;
		for (i=1;i<m;i++) ws[i]+=ws[i-1];
		for (i=n-1;i>=0;i--) 
		    sa[--ws[wv[i]]]=y[i];
		
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

int main() {
	int i,j,l1,l2,ans,len;
	scanf("%s",a);
	l1=strlen(a);
	for (i=0;i<l1;i++) s[i]=a[i]-'a'+1;
	scanf("%s",a);
	l2=strlen(a);
	s[l1]=0;
	for (i=l1+1;i<=l1+l2;i++) s[i]=a[i-l1-1]-'a'+1;
	len=l1+l2+1;
	s[len]=0;
	build(s,sa,len+1,28);
	ans=0;
	for (i=2;i<=len-1;i++) {
		if ((sa[i-1]<l1&&sa[i]>l1)||(sa[i-1]>l1&&sa[i]<l1)) 
		    ans=max(ans,height[i]);
	}
	printf("%d\n",ans);
}
