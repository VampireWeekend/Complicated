#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100005;
int num;
struct Tree {
	bool num;
	int lc,rc;
};
Tree tree[maxn*60];
int a[33];

void insert(int now,int v,int depth) {
		if (tree[now].num==0) {
			tree[now].num=1;
			num++;
			tree[now].lc=num;
			tree[num].num=0;
			num++;
			tree[now].rc=num;
			tree[num].num=0;
		}
		if (depth==-1) return;
		if ((v>>depth)%2==1) 
			insert(tree[now].rc,v,depth-1); 
		else 
			insert(tree[now].lc,v,depth-1);
}

int find(int now,int v,int depth) {
	if (depth<0) return 0;
	if ((v>>depth)%2==1)  {
		if (tree[tree[now].lc].num) 
	        return find(tree[now].lc,v,depth-1)+a[depth]; 
    	else 
	    	return find(tree[now].rc,v,depth-1);
	} else {
		if (tree[tree[now].rc].num) 
	     	return find(tree[now].rc,v,depth-1)+a[depth]; 
    	else 
	    	return find(tree[now].lc,v,depth-1);
	}
}

int main() {
	int n,i,m,x;
	a[0]=1;
	for (i=1;i<=30;i++) a[i]=a[i-1]*2;
	scanf("%d",&n);
	num=1;
	tree[1].num=0;
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		insert(1,x,30); 
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		int f;
		scanf("%d",&x);
		f=find(1,x,30);
		printf("%d\n",f);
	}
	return 0;
}
/*
5
1 8 0 5 14
5
7 14 10 4 2
*/
