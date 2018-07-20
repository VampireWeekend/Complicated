#include <cstdio>
#include <string.h>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
int wa[maxn],wb[maxn],ws[maxn],wv[maxn],sa[maxn],height[maxn],ranki[maxn];
int mn[maxn][20];
int a[maxn];
char s[maxn];

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

void rmq(int n) {
	int i,j;
	for (i=1;i<=n;i++) mn[i][0]=height[i];
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}

int lcp(int a,int b) {
	int fa=ranki[a],fb=ranki[b];
	if (fa>fb) swap(fa,fb);
	fa++;
	int k=0;
	while ((1<<(k+1))<=(fb-fa+1)) k++;
	return min(mn[fa][k],mn[fb-(1<<k)+1][k]);
}

int main() {
	int cas=0;
	while (1) {
		cas++;
		scanf("%s",s);
		if (s[0]=='#') break;
		int i,j,k,len,maxlen,st,l,ans;
		len=strlen(s);
		ans=maxlen=1;st=0;
		for (i=0;i<len;i++) {
			if (s[i]<s[st]) st=i;
			a[i]=s[i]-'a'+1;
		}
		a[len]=0;
		build(a,sa,len+1,27);
		rmq(len);
		for (i=1;i<=len;i++) {
			for (j=0;j+i<len;j+=i) {
				int l=lcp(j,j+i);
				if (l==0) continue;
				for (k=j-1;k>=max(j-i+1,0);k--) {
					if (l/i+1>ans||(l/i+1==ans&&ranki[st]>ranki[k+1])) {
						ans=l/i+1;
						maxlen=i;
						st=k+1;
					}
					if (a[k]!=a[k+i]) break;
					l++;
				}
				if (l/i+1>ans||(l/i+1==ans&&ranki[st]>ranki[k+1])) {
					ans=l/i+1;
					maxlen=i;
					st=k+1;
				}
			}
		}
		printf("Case %d: ",cas);
		for (j=1;j<=ans;j++)
			for (i=0;i<maxlen;i++) 
				printf("%c",s[st+i]);
		printf("\n");
	}
	return 0;
}

