#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=100500;
const int inf=0x3f3f3f3f;
struct Point {
	int x,y;
};
Point point[maxn];
int r[maxn];
int num;
struct Tree {
	int lc,rc,l,r,sum,tag;
};
Tree tree[4*maxn];

bool cmp(Point a,Point b) {
	return (a.x<b.x)||(a.x==b.x&&a.y<b.y);
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].sum=tree[now].tag=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << endl;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag+=tree[now].tag;
	tree[r].tag+=tree[now].tag;
	tree[l].sum+=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum+=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[now].tag=0;
}

void update (int now,int l,int r,int c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag+=c;
		tree[now].sum+=c*(tree[now].r-tree[now].l+1);
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
}

int findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		pushdown(now);
		int f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f;
	}
}

int main() {
	int n,i,maxy;
	maxy=-1;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&point[i].x,&point[i].y);
		maxy=max(maxy,point[i].y); 
		r[i]=0;
	} 
	num=1;
	sort(point+1,point+n+1,cmp);
	build(1,1,maxy);
	for (i=1;i<=n;i++) {
		int f=findsum(1,point[i].y,point[i].y);
		r[f]++;
		update(1,point[i].y,maxy,1);
	}
	for (i=0;i<n;i++) printf("%d\n",r[i]);
	return 0;
}

/*
8
100000 100000
999 999
900 4200
100 86
80 45
40 80
40 20
1 4

*/
