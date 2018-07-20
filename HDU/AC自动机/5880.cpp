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
const int maxn=1000005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int q[maxn],b[maxn];
char t[maxn];
int num;

struct node{
    int fail,next[maxk]; 
    int cnt,len;
    void init() {
        fail=-1;
        for (int i=0;i<maxk;i++) next[i]=-1;
        cnt=len=0;
    }
};
node a[maxn];

void insert(int root,int len) {
    int now=root;
    int i;
    for (i=0;i<len;i++) {
        int pos=t[i]-'a';
        if (a[now].next[pos]==-1) {
            a[now].next[pos]=++num;
            a[num].init();
        }
        now=a[now].next[pos];
    }
    a[now].cnt++;
    a[now].len=max(a[now].len,len);
}

void buildfail(int root) {
    int p=root;
    int front=0,tail=0,i;
    for (i=0;i<maxk;i++) {
        if (a[p].next[i]!=-1) {
            a[a[p].next[i]].fail=root;
            q[tail++]=a[p].next[i];
        } else a[p].next[i]=root;
    }
    while (front<tail) {
        p=q[front];
        for (i=0;i<maxk;i++) {
            if (a[p].next[i]==-1) 
                a[p].next[i]=a[a[p].fail].next[i];
            else {
                a[a[p].next[i]].fail=a[a[p].fail].next[i];
                q[tail++]=a[p].next[i];
            }
        }
        front++;
    }
}

void search(string s,int root,int len) {  
    int k=0,i;  
    int p=root,now;  
    for (i=0;i<len;i++) {
        if (s[i]>='a'&&s[i]<='z') p=a[p].next[s[i]-'a']; else {
        	p=root;continue;
        }
        now=p;  
        while (now!=root&&a[now].cnt!=-1) {  
            if (a[now].cnt) {
                b[i-a[now].len+1]++;
                b[i+1]--;
            }
            now=a[now].fail;  
        }
    }
}  

int main() {
    num=0;
    string s,w;
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,i,j,len;
        mem0(b);
        scanf("%d",&n);
        num=0;
        a[0].init();
        for (i=1;i<=n;i++) {
            scanf("%s",t);
            len=strlen(t);
            insert(0,len);
        }
        getchar();
        getline(cin,s);
        len=s.length();w=s;
        for (i=0;i<len;i++) {
            if (s[i]>='A'&&s[i]<='Z') s[i]=(char)('a'-'A'+s[i]);
        }
        buildfail(0);
        search(s,0,len);
        int sum=0;
        for (i=0;i<len;i++) {
            sum+=b[i];
            if (sum>0) printf("*"); else printf("%c",w[i]);
        }
        printf("\n");
    }
    return 0;
}
