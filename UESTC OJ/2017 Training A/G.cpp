#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=500005;
const int inf=0x3f3f3f3f;
struct Tree {
	int l,r,lc,rc,lms,rms,ms,sum;
};
Tree tree[maxn*4];
int num;

int max(int a,int b) {
	if (a>b) return a; else return b;
}

void pushup(int now) {
	int l=tree[now].lc,r=tree[now].rc;
	tree[now].ms=max(tree[l].ms,tree[r].ms);
	tree[now].ms=max(tree[now].ms,tree[l].rms+tree[r].lms);
	tree[now].sum=tree[l].sum+tree[r].sum;
	tree[now].lms=max(tree[l].lms,tree[l].sum+tree[r].lms);
	tree[now].rms=max(tree[r].rms,tree[r].sum+tree[l].rms);
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	if (l==r) {
		scanf("%d",&tree[now].ms);
		tree[now].sum=tree[now].rms=tree[now].lms=tree[now].ms;
	} else {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		pushup(now);
	}
}

void update(int now,int l,int r,int c) {
	if (l<=tree[now].l&&r>=tree[now].r) {
		tree[now].sum=tree[now].lms=tree[now].rms=tree[now].ms=c;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2) 
		    update(tree[now].rc,l,r,c);
		pushup(now);
    }
}

Tree findms(int now,int l,int r) {
	if (l<=tree[now].l&&r>=tree[now].r) {
		return tree[now];
	} else if (r<=tree[tree[now].lc].r) return findms(tree[now].lc,l,r); else
	   if (l>=tree[tree[now].rc].l) return findms(tree[now].rc,l,r); else {
	   	    Tree fl=findms(tree[now].lc,l,r),fr=findms(tree[now].rc,l,r);
	   	    Tree f=tree[now];
	   	    f.ms=max(fl.ms,fr.ms);
        	f.ms=max(f.ms,fl.rms+fr.lms);
        	f.sum=fl.sum+fr.sum;
         	f.lms=max(fl.lms,fl.sum+fr.lms);
         	f.rms=max(fr.rms,fr.sum+fl.rms);
         	return f;
	   }
}

int main() {
	int i,n,m,a,b,x;
	scanf("%d%d",&n,&m);
	num=1;
	build(1,1,n);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&a,&b);
		if (x==1) printf("%d\n",findms(1,a,b).ms);
		    else update(1,a,a,b);
	}
	return 0;
}
/*
5
1 2 -3 4 5
3
1 2 3
0 2 -1
1 2 5
*/
