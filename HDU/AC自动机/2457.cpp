#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <queue>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1005,inf=0x3f3f3f3f,maxk=4;
char s[maxn];
char d[4];
int dp[maxn][maxn];
int id['Z'+1];
int num;

struct node{
	struct node *fail;
	struct node *next[maxk];
	int cnt,id;
	void init() {
		fail=NULL;
		for (int i=0;i<maxk;i++) next[i]=NULL;
		cnt=0;
		id=++num;
	}
};
node *a[maxn],*q[maxn];

void insert(string s,node *root,int len) {
	node *now=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=id[s[i]];
		if (now->next[pos]==NULL) {
	    	now->next[pos]=new node;
	    	now->next[pos]->init();
	    	a[num]=now->next[pos];
    	}
    	now=now->next[pos];
	}
	now->cnt++;
}

void buildfail(node *root) {
	node *p=root;
	int front=0,tail=0,i;
	for (i=0;i<maxk;i++) {
		if (p->next[i]!=NULL) {
			p->next[i]->fail=root;
			q[tail++]=p->next[i];
		} else p->next[i]=root;
	}
	while (front<tail) {
		p=q[front];
		for (i=0;i<maxk;i++) {
			if (p->next[i]==NULL) 
			    p->next[i]=p->fail->next[i];
			else {
				node *x=p->fail;
				while (x!=NULL) {
					if (x->next[i]!=NULL) {
						p->next[i]->fail=x->next[i];
						break;
					}
					x=x->fail;
				}
				if (p->fail->next[i]->cnt) p->next[i]->cnt++;
				q[tail++]=p->next[i];
			}
		}
		front++;
	}
}

int main() {
	int cas=0,n;
	scanf("%d",&n);
	id['A']=0;id['T']=1;id['C']=2;id['G']=3;
	d[0]='A';d[1]='T';d[2]='C';d[3]='G';
	while (n) {
		int i,len,j,k;
		cas++;
		num=0;
		node *root=new node;
		root->init();
		a[1]=root;
		for (i=1;i<=n;i++) {
			scanf("%s",s);
			insert(s,root,strlen(s));
		}
		buildfail(root);
		scanf("%s",s);
		len=strlen(s);
		meminf(dp);
		dp[0][1]=0;
		for (i=1;i<=len;i++) {
			for (j=1;j<=num;j++) {
				if (dp[i-1][j]==inf) continue;
				for (k=0;k<4;k++) {
					if (a[j]->next[k]->cnt==0) {
						dp[i][a[j]->next[k]->id]=
						min(dp[i][a[j]->next[k]->id],
						dp[i-1][j]+(d[k]==s[i-1]?0:1));
					}
				}
			}
		}
		int ans=inf;
		for (i=1;i<=num;i++) 
		    ans=min(ans,dp[len][i]);
		if (ans==inf) ans=-1;
		printf("Case %d: %d\n",cas,ans);
		scanf("%d",&n);
    }
	return 0;
}

