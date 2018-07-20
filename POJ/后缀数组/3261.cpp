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
const int maxn=20005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
int s[maxn];

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

bool check(int l,int n,int k) {
	int i,mi,ma,cnt=1;
	for (i=2;i<=n;i++) {
		if (height[i]>=l) cnt++; else {
			if (cnt>=k) return true;
			cnt=1;
		}
	}
	if (cnt>=k) return true;
	return false;
}

int main() {
	int n,k;
	while (scanf("%d%d",&n,&k)!=EOF) {
		int i,m=-1;
		for (i=0;i<n;i++) {
			scanf("%d",&s[i]);
			m=max(m,s[i]); 
		}
		s[n]=0;
		build(s,sa,n+1,m+1);
		int l=1,r=n,mid,ans=-1;
    	while (l<=r) {
    		mid=(l+r)/2;
    		if (check(mid,n,k)) ans=mid,l=mid+1; else r=mid-1;
    	}
    	printf("%d\n",ans); 
	}
	return 0;
}

