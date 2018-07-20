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
const int maxn=100005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn],t[maxn]; 

struct SAM {  
	int num,last;  
    struct node{  
        int len,fa,maxlen;  
        int son[maxk];  
    } a[maxn*2];  
    void init() {  
        num=last=0;  
        a[0].len=0;a[0].fa=-1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;
        a[now].maxlen=0;
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
                a[ne].maxlen=0;
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
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
};  
SAM sa;

ll dp[maxn*2];
bool visit[maxn*2];
int w[maxn*2],r[maxn*2];
ll topsort(int len) {
    int m=sa.getnum(),i,j;
    ll ans=0;
    mem0(w);
    for(i=0;i<=m;i++) w[sa.getlen(i)]++;  
    for(i=0;i<=len;i++) w[i]+=w[i-1];  
    for(i=m;i>=0;i--) r[--w[sa.getlen(i)]]=i;  
    for (i=m;i>0;i--) {
    	ans+=sa.a[r[i]].len-max(sa.getlen(sa.getfa(r[i])),sa.a[r[i]].maxlen);
    	if (sa.a[r[i]].maxlen>0)
			sa.a[sa.getfa(r[i])].maxlen=sa.a[sa.getfa(r[i])].len;
    }
    return ans;
}

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		int n,i,j,len;
		scanf("%d",&n);
		scanf("%s",s);
		len=strlen(s);
		sa.init();
		for (i=0;i<len;i++) sa.update(s[i]-'a');
		for (i=1;i<=n;i++) {
			scanf("%s",t);
			len=strlen(t);
			int now=0,l=0;
			for (j=0;j<len;j++) {
				if (sa.getson(now,t[j]-'a')!=-1) {
					l++;
					now=sa.getson(now,t[j]-'a');
					sa.a[now].maxlen=max(sa.a[now].maxlen,l);
				} else {
					while (now!=-1&&sa.getson(now,t[j]-'a')==-1)
						now=sa.getfa(now);
					if (now==-1) {
						l=0;
						now=0;
					} else {
						l=sa.getlen(now)+1;
						now=sa.getson(now,t[j]-'a');
						sa.a[now].maxlen=max(sa.a[now].maxlen,l);
					}
				}
			}
		}
		len=strlen(s);
		mem0(dp);
		ll ans=topsort(len);
		printf("Case %d: %lld\n",cnt,ans);
	}
	return 0;
}
