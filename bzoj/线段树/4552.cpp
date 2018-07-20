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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],l[maxn],r[maxn],w[maxn];
int num,q;

struct Tree {
	int lc,rc,l,r,sum,tag;
};
Tree tree[4*maxn];

void build(int now,int l,int r,int c) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=-1;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2,c);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	} else tree[now].sum=a[l]>=c?1:0;
}

void pushdown(int now) {
	if (tree[now].tag==-1) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag=tree[now].tag;
	tree[r].tag=tree[now].tag;
	tree[l].sum=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[now].tag=-1;
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].sum=c*(tree[now].r-tree[now].l+1);
		tree[now].tag=c; 
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
}

int findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	pushdown(now);
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		int f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f;
	}
}

bool check(int n,int m,int mid) {
	int i,sum;
	num=1;
	build(1,1,n,mid);
	for (i=1;i<=m;i++) {
		sum=findsum(1,l[i],r[i]);
//		cout << '\n';
		if (sum>0) {
			if (w[i]) update(1,l[i],l[i]+sum-1,1); else
				update(1,r[i]-sum+1,r[i],1);
		} 
//		cout << '\n';
		if (sum!=r[i]-l[i]+1) {
			if (!w[i]) update(1,l[i],r[i]-sum,0); else
				update(1,l[i]+sum,r[i],0);
		}
//		cout << '\n';
	}
	return findsum(1,q,q);
}

int main() {
	int n,m,i,j,pos;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&w[i],&l[i],&r[i]);
	}
	int L,R,mid,ans;
	L=1;R=n;
	scanf("%d",&q);
	while (L<=R) {
		mid=(L+R)/2;
		if (check(n,m,mid)) ans=mid,L=mid+1; else R=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
