#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int maxk=128,maxn=10005;
char s[maxn],a[maxk*2];
struct node {
	struct node *fail;
	struct node *nxt[maxk];
	int cnt,id;
	
	void init() {
		for (int i=0;i<maxk;i++) nxt[i]=NULL;
		fail=NULL;
		cnt=id=0;
	}
};

void insert(string s,node *root,int len,int id) {
	node *p=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=s[i];
		if (p->nxt[pos]==NULL) {
			p->nxt[pos]=new node;
			p->nxt[pos]->init();
		}
		p=p->nxt[pos];
	}
	p->cnt++;
	p->id=id;
}

void buildfail(node *root) {
	node *p=root;
	node *now;
	int front=0,tail=0,i;
	queue<node *> q;
	for (i=0;i<maxk;i++) {
		if (p->nxt[i]!=NULL) {
			p->nxt[i]->fail=root;
			q.push(p->nxt[i]);
		} else p->nxt[i]=root;
	}
	while (!q.empty()) {
		now=q.front();
		q.pop();
		for (i=0;i<maxk;i++) {
	    	if (now->nxt[i]!=NULL) {
		    	now->nxt[i]->fail=now->fail->nxt[i];
		    	q.push(now->nxt[i]);
	    	} else now->nxt[i]=now->fail->nxt[i];
    	}
	}
}

bool search(string s,node *root,int len,int cas) {
	int k=0,i;
	node *q[3];
	node *p=root,*now;
	for (i=0;i<len;i++) {
		p=p->nxt[s[i]];
		now=p;
		while (now!=root&&now->cnt!=-1) {
			if (now->cnt) {
				q[k++]=now;
				now->cnt=-1;
			}
			now=now->fail;
		}
 	}
 	if (k) {
 		printf("web %d:",cas);
 		int id[3];
 		for (i=0;i<k;i++) id[i]=q[i]->id;
 		sort(id,id+k);
 		for (i=0;i<k;i++) {
 			printf(" %d",id[i]);
 			q[i]->cnt=1;
 		}
 		printf("\n");
 		return true;
 	}
	return false;
}

int main() {
	int n,len,i,j,tot=0;
	node *root=new node;
	root->init();
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%s",a);
		insert(a,root,strlen(a),i);
	}
	buildfail(root);
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%s",s);
		tot+=search(s,root,strlen(s),i);
	}
	printf("total: %d\n",tot);
	return 0;
}
