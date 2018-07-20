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
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
const int maxn=90005,maxk=26,inf=0x3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];
ull dpa[maxn*2],dpb[maxn*2];

struct SAM {  
	int num,last,maxlen;  
    struct node{  
        int len,fa;  
        int son[maxk];  
    } a[maxn*2];  
    void init() {  
        num=last=maxlen=0;  
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
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
};  
SAM sa,sb;

bool visit[maxn*2];
void dfsb(int now) {
	visit[now]=1;
	dpb[now]=1;
	for (int i=0;i<maxk;i++) {
		int to=sb.getson(now,i);
		if (to!=-1) {
			if (!visit[to]) dfsb(to);
			dpb[now]+=dpb[to];
		}
	}
}

void dfs(int now) {
	visit[now]=1;
	dpa[now]=1;
	for (int i=0;i<maxk;i++) {
		int to=sa.getson(now,i);
		if (to!=-1) {
			if (!visit[to]) dfs(to);
			dpa[now]+=dpa[to];
		} else {
			int t=sb.getson(0,i);
			if (t!=-1) dpa[now]+=dpb[t];
		}
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%s",s);
		scanf("%s",t);
		int len=strlen(t),i,j;
		sa.init();sb.init();
		mem0(dpa);mem0(dpb);
		for (i=0;i<len;i++) 
			sb.update(t[i]-'a');
		mem0(visit);dfsb(0);
		len=strlen(s);
		for (i=0;i<len;i++) 
			sa.update(s[i]-'a');
		int now=0;
		mem0(visit);
		for (i=0;i<len;i++) {
			now=sa.getson(now,s[i]-'a');
			dpa[now]++;
  		}
		dfs(0);
		printf("%I64u\n",dpa[0]);
	}
	return 0;
}
