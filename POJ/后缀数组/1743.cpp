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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
int s[maxn],a[maxn];

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
	//sa[i]表示排名第i位的后缀的起始位置 
	for (j=1,p=1;p<n;j*=2,m=p) {
		for (p=0,i=n-j;i<n;i++) 
		    y[p++]=i;
		for (i=0;i<n;i++) 
		    if (sa[i]>=j) y[p++]=sa[i]-j;
		// w[i]表示第二关键字排名第i位的位置 
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
		//前后两个排名相近的字符串是否完全相同
		//x[]记录排名 
	}
	
	for (i=1;i<n;i++) ranki[sa[i]]=i;
	k=0; 
	for (i=0;i<n-1;height[ranki[i++]]=k) {
		if (k) k--;
		for (j=sa[ranki[i]-1];r[i+k]==r[j+k];k++);
	}
}

bool check(int l,int n) {
	int i,mi,ma;
	mi=ma=sa[1];
	for (i=2;i<=n;i++) {
		if (height[i]<l) {
			if (ma-mi>l) return true;
			ma=mi=sa[i];
		} else {
			ma=max(ma,sa[i]);
			mi=min(mi,sa[i]);
		}
	}
	if (ma-mi>l) return true;
	return false;
}

int main() {
	int len;
    scanf("%d",&len);
    while (len) {
    	for (int i=0;i<len;i++) {
    		scanf("%d",&a[i]);
    		if (i!=0) s[i-1]=a[i]-a[i-1]+88;
    	}
    	s[len-1]=0;
    	build(s,sa,len,176);
    	int l=1,r=len,mid,ans=-1;
    	while (l<=r) {
    		mid=(l+r)/2;
    		if (check(mid,len-1)) ans=mid,l=mid+1; else r=mid-1;
    	}
    	ans++;
    	if (ans<5) ans=0;
    	printf("%d\n",ans);
    	scanf("%d",&len);
    }
	return 0;
}

