#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=500005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
ll wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
char a[maxn];
ll s[maxn],l[maxn],r[maxn],st[maxn];

ll cmp(ll *r,ll a,ll b,ll l) {
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void build(ll *r,ll *sa,ll n,ll m) {
	ll i,j,k,p,*x=wa,*y=wb,*t;
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
	scanf("%s",a);  
    ll n=strlen(a),i,j;  
    for (i=0;i<n;i++) {  
        s[i]=a[i]-'a'+1;  
    }  
    s[n]=0;  
    build(s,sa,n+1,27);  
    ll ans=n*(n+1)/2*(n-1);
    ll top=0;
    for (i=2;i<=n;i++) {
        while (top&&height[i]<height[st[top]]) 
			r[st[top--]]=i-1;
        st[++top]=i;
    }
    while (top) r[st[top--]]=n;
    for (i=n;i>=2;i--) {
        while (top&&height[i]<=height[st[top]]) 
			l[st[top--]]=i+1;
        st[++top]=i;
    }
    while (top) l[st[top--]]=2;
    for (i=2;i<=n;i++)
        ans-=2ll*height[i]*(i-l[i]+1)*(r[i]-i+1); 
    printf("%lld\n",ans);
	return 0;
}
