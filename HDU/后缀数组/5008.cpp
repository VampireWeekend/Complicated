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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
int s[maxn];
ll sum[maxn];
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
	while (scanf("%s",a)!=EOF) {
		int n,i,j,q;
		ll k;
		scanf("%d",&q);
		n=strlen(a);
		for (i=0;i<n;i++) 
			s[i]=a[i]-'a'+1;
		s[n]=0;
		build(s,sa,n+1,27);
		sum[0]=0;sum[1]=n-sa[1];
		for (i=2;i<=n;i++) 
			sum[i]=sum[i-1]+n-sa[i]-height[i];
		int l,r,len;
		l=r=0;
		for (i=1;i<=q;i++) {
			scanf("%lld",&k);
			k=(l^r^k)+1;
			if (k>sum[n]) {
				l=r=0;
				printf("0 0\n");
			} else {
				int pos=lower_bound(sum+1,sum+n,k)-sum;
				l=sa[pos]+1;len=k-sum[pos-1]+height[pos];
				for (j=pos+1;j<=n;j++) {
					if (height[j]<len) break;
					l=min(l,sa[j]+1);
				}
				r=l+len-1;
				printf("%d %d\n",l,r);
			}
		}
	}
	return 0;
}

