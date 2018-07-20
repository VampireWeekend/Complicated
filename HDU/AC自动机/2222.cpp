//AC Automation
//Ä£°å 
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=1000005,maxk=26;
char a[54],s[maxn];
int m;
struct node {
	struct node *fail;
	struct node *next[maxk];
	int cnt;
	void init () {
		fail=NULL;
		for (int i=0;i<maxk;i++) next[i]=NULL;
		cnt=0;
	}
};
node *q[maxn];

void insert(string s,node *root,int len) {
	node *now=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=s[i]-'a';
		if (now->next[pos]==NULL) {
	    	now->next[pos]=new node;
	    	now->next[pos]->init();
    	}
    	now=now->next[pos];
	}
	now->cnt++;
}
//buildfail,O(nk)
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
				p->next[i]->fail=p->fail->next[i];
				q[tail++]=p->next[i];
			}
		}
		front++;
	}
}

ll find(string s,node *root,int len) {
	node *p=root,*now;
	int i;
	ll ans=0;
	for (i=0;i<len;i++) {
		p=p->next[s[i]-'a'];
		now=p;
		while (now!=root&&now->cnt!=-1) {
			if (now->cnt) {
				ans+=(ll)now->cnt;
				now->cnt=-1;
			}
			now=now->fail;
		}
	}
	return ans;
}

int main() {
	int q,t,i,j;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		node *root=new node;
		root->init();
		int n;
		m=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%s",a);
			insert(a,root,strlen(a));
		}
		scanf("%s",s);
		ll len=(ll)strlen(s);
		buildfail(root);
		ll ans=find(s,root,len);
		printf("%lld\n",ans);
	}
	return 0;
}
