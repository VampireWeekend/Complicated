#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=120005,maxk=11,inf=0x3f3f3f3f,mod=2012;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

class SAM {  
    public:  
    void init() {  
        num=last=0;  
        a[0].len=0;a[0].fa=-1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;  
        maxlen=max(maxlen,a[now].len);
        memset(a[now].son,-1,sizeof(a[now].son));  
        for (p=last;p!=-1&&a[p].son[c]==-1;p=a[p].fa)  
            a[p].son[c]=now;  
        if (p==-1) a[now].fa=0; else {
            int q=a[p].son[c];  
            if (a[p].len+1==a[q].len) {
                a[now].fa=q;  
            } else {  
                int ne=++num;  
                a[ne].len=a[p].len+1;  
                maxlen=max(maxlen,a[ne].len);
                memcpy(a[ne].son,a[q].son,sizeof(a[q].son));  
                a[ne].fa=a[q].fa;  
                for (;p!=-1&&a[p].son[c]==q;p=a[p].fa)   
                    a[p].son[c]=ne;  
                a[q].fa=a[now].fa=ne;  
            }  
        }  
        last=now;  
    }  
    int getfa(int n) {
    	return a[n].fa;
    }
    int getlen(int n) {
    	return a[n].len;
    }
    int getmaxlen() {
    	return maxlen;
    }
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
    private:  
    int num,last,maxlen;  
    struct node{  
        int len,fa;  
        int son[maxk];  
    } a[maxn*2];  
};  
SAM sa;

int w[maxn*2],r[maxn*2],dp[maxn*2],sum[maxn*2];
int topsort() {
    int m=sa.getnum(),i,j,ans=0;
    mem0(w);
    int len=sa.getmaxlen();
    for(i=0;i<=m;i++) w[sa.getlen(i)]++;  
    for(i=0;i<=len;i++) w[i]+=w[i-1];  
    for(i=m;i>=0;i--) r[--w[sa.getlen(i)]]=i;  
    int now=0; 
    mem0(dp);mem0(sum);
    dp[0]=1;
    for (i=0;i<=m;i++) {
    	for (j=0;j<10;j++) {
    		if (i==0&&j==0) continue;
    		int to=sa.getson(r[i],j);
    		if (to!=-1) {
    			dp[to]+=dp[r[i]];
    			dp[to]%=mod;
    			sum[to]+=sum[r[i]]*10+j*dp[r[i]];
    			sum[to]%=mod;
    		}
    	}
    	ans+=sum[r[i]];
    	ans%=mod;
    }
    return ans;
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		sa.init();
		int i,j;
		for (i=1;i<=n;i++) {
			scanf("%s",s);
			int len=strlen(s);
			for (j=0;j<len;j++) 
				sa.update(s[j]-'0');
			sa.update(10);
		}
		int ans=topsort();
		printf("%d\n",ans);
	}
	return 0;
}
