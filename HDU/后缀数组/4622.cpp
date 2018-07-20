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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
int s[maxn];
int mn[maxn][12],lcp[maxn];
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

void init(int n) {
	int i,j;
	for (i=1;i<=n;i++) mn[i][0]=height[i];
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}

int rmq(int a,int b) {
	int fa=ranki[a],fb=ranki[b];
	if (fa>fb) swap(fa,fb);
	fa++;
	int k=0;
	while ((1<<(k+1))<=(fb-fa+1)) k++;
	return min(mn[fa][k],mn[fb-(1<<k)+1][k]);
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%s",a);
		int n=strlen(a),i,j;
		for (i=0;i<n;i++) {
			s[i]=a[i]-'a'+1;
		}
		s[n]=0;
		build(s,sa,n+1,27);
		init(n);
		int q,l,r,ans;
		scanf("%d",&q);
		for (i=1;i<=q;i++) {
			scanf("%d%d",&l,&r);
			ans=(r-l+1)*(r-l+2)/2;
			r--;l--;
			int last=-1;
			for (j=1;j<=n;j++) {
				if (sa[j]>=l&&sa[j]<=r) {
					if (last==-1) last=j; else {
						int len=rmq(sa[last],sa[j]);
						int k=min(r-sa[last]+1,r-sa[j]+1);
						if (!(sa[last]<sa[j]&&len>=k)) last=j;
						len=min(len,k);
						ans-=len;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

