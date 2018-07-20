//线段树，加法、乘法标记，区间求和 
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=100500;
int num;
struct Tree {
	int lc,rc,l,r;
	ll tag,sum,mul;
};
Tree tree[4*maxn];
ll p;

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	tree[now].mul=1;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
		tree[now].sum%=p;
	} else scanf("%lld",&tree[now].sum);
}

void pushdown(int now) {
	int l=tree[now].lc;
	int r=tree[now].rc;
	tree[l].tag=(tree[l].tag*tree[now].mul+tree[now].tag)%p;
	tree[r].tag=(tree[r].tag*tree[now].mul+tree[now].tag)%p;
	tree[l].mul*=tree[now].mul;
	tree[l].mul%=p;
	tree[r].mul*=tree[now].mul;
	tree[r].mul%=p;
	tree[l].sum*=tree[now].mul;
	tree[l].sum+=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[l].sum%=p;
	tree[r].sum*=tree[now].mul;
	tree[r].sum+=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[r].sum%=p;
	tree[now].tag=0;tree[now].mul=1;
}

void add(int now,int l,int r,ll c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag+=c;
		tree[now].tag%=p;
		tree[now].sum+=c*(tree[now].r-tree[now].l+1);
		tree[now].sum%=p;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    add(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    add(tree[now].rc,l,r,c);
		tree[now].sum=(tree[tree[now].lc].sum+tree[tree[now].rc].sum)%p;
	}
}

void multiply(int now,int l,int r,ll c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag*=c;
		tree[now].tag%=p;
		tree[now].mul*=c;
		tree[now].mul%=p;
		tree[now].sum*=c;
		tree[now].sum%=p;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    multiply(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    multiply(tree[now].rc,l,r,c);
		tree[now].sum=(tree[tree[now].lc].sum+tree[tree[now].rc].sum)%p;
	}
}

ll findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << ' ' << tree[now].mul << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		pushdown(now);
		ll f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f%p;
	}
}

int main() {
	int n,m,l,op,r,k;
	ll c; 
	scanf("%d%lld",&n,&p);
	num=1;
	build(1,1,n);
	scanf("%d",&m);
	for (k=1;k<=m;k++) {
		scanf("%d",&op);
		if (op==1) {
			scanf("%d%d%lld",&l,&r,&c);
			multiply(1,l,r,c);
		} else if (op==2) {
			scanf("%d%d%lld",&l,&r,&c);
			add(1,l,r,c);
		} else {
			scanf("%d%d",&l,&r);
			ll ans=findsum(1,l,r);
			printf("%lld\n",ans);
		}
//		if (op!=3)
//		for (int now=1;now<=num;now++)
//		cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << endl;
	}
	return 0;
}
