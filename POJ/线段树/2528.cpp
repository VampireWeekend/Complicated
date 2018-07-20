#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=40005;
int a[maxn],b[maxn],l[maxn],r[maxn],f[maxn];
int num,ans;

struct Tree {
	int l,r,lc,rc,tag;
};
Tree tree[4*maxn];

void pushdown(int now) {
	if (!tree[now].tag) return;
	tree[tree[now].lc].tag=tree[now].tag;
	tree[tree[now].rc].tag=tree[now].tag;
	tree[now].tag=0;
}

void build(int now,int l,int r) {
	tree[now].tag=0;
	tree[now].l=l;tree[now].r=r;
	if (l==r) 
		return;
	num++;
	tree[now].lc=num;
	build(num,l,(l+r)/2);
	num++;
	tree[now].rc=num;
	build(num,(l+r)/2+1,r);
}

void update(int now,int l,int r,int val) {
	if (l<=tree[now].l&&tree[now].r<=r) {
		tree[now].tag=val;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2)
		    update(tree[now].lc,l,r,val);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,val);
	}
}

void find(int now) {
//	cout << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag << endl;
	if (tree[now].tag) {
		if (!f[tree[now].tag]) {
			f[tree[now].tag]=1;
			ans++;
		}
		tree[now].tag=0;
	} else {
		if (tree[now].l==tree[now].r) return;   //因为这句话挂了很多次 
		pushdown(now);
		find(tree[now].lc);
	    find(tree[now].rc);
	}
}

int search(int val,int x,int y) {
	int l=x,r=y;
	while (l<=r) {
		int mid=(l+r)/2;
		if (b[mid]==val) return mid; else 
		if (b[mid]>val) r=mid-1; else l=mid+1;
	}
	return -1;
}

int main() {
	int n,m,i,t,q;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d%d",&l[i],&r[i]);
			a[2*i-1]=l[i];
			a[2*i]=r[i];
		}
		sort(a+1,a+n*2+1);
		m=1;
		b[1]=a[1];
		for (i=2;i<=n*2;i++) {
			if (a[i]-a[i-1]>1) b[++m]=a[i]-1;
			if (a[i]!=a[i-1]) b[++m]=a[i];
		}
		sort(a+1,a+m+1);
		num=1;
		build(1,1,m);
		for (i=1;i<=n;i++) {
			int nowl,nowr;
			nowl=search(l[i],1,m);
			nowr=search(r[i],1,m);
			update(1,nowl,nowr,i);
		}
		memset(f,0,sizeof(f));
		ans=0;
		find(1);
		printf("%d\n",ans);
	} 
	return 0;
}
