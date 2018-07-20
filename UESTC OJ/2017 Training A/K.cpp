#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=100500;
const long long inf=1e13;
typedef long long ll;
int num;
struct Tree {
	int lc,rc,l,r;
	ll sum,ms,lms,rms;
};
Tree tree[4*maxn];

ll max (ll a,ll b) {
	if (a>b) return a; else return b;
}

void pushup(int now) {
	int l=tree[now].lc,r=tree[now].rc;
	tree[now].sum=tree[l].sum+tree[r].sum;
	tree[now].ms=max(tree[l].ms,tree[r].ms);
	tree[now].ms=max(tree[now].ms,tree[l].rms+tree[r].lms);
	tree[now].lms=max(tree[l].lms,tree[l].sum+tree[r].lms);
	tree[now].rms=max(tree[r].rms,tree[r].sum+tree[l].rms);
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		pushup(now);
	} else {
		scanf("%lld",&tree[now].sum);
		tree[now].ms=tree[now].lms=tree[now].rms=tree[now].sum;
	}
}

void update (int now,int l,int r) {
//	if (l==21723)cout << tree[now].sum << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].lms << ' ' << tree[now].rms << ' ' << tree[now].ms << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].ms=tree[now].lms=tree[now].rms=tree[now].sum=-inf;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r);
	    pushup(now);
	}
}

int main() {
	int n,i,x;
	scanf("%d",&n);
	num=1;
	build(1,1,n);
	for (i=1;i<n;i++) {
		scanf("%d",&x);
		update(1,x,x);
		printf("%lld\n",tree[1].ms);
	}
	printf("0");
	return 0;
}

