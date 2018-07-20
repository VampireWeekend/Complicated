#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int root[maxn],r[maxn];
int num;

struct portland{
	int id,val;
};
portland a[maxn];

struct node{
	int l,r,cnt;
};
node tree[maxn*40];

bool cmp(portland a,portland b) {
	return a.val<b.val;
}

int build(int l,int r) {
	int k=num++;
	tree[k].cnt=0;
	if (l==r) return k;
	tree[k].l=build(l,(l+r)/2);
	tree[k].r=build((l+r)/2+1,r);
	return k;
}

int update(int now,int l,int r,int pos,int val){
	int k=num++;
	tree[k]=tree[now];
	if (l==pos&&r==pos) {
		tree[k].cnt+=val;
		return k;
	}
	if (pos<=(l+r)/2) tree[k].l=update(tree[now].l,l,(l+r)/2,pos,val);
	    else tree[k].r=update(tree[now].r,(l+r)/2+1,r,pos,val);
	tree[k].cnt=tree[tree[k].l].cnt+tree[tree[k].r].cnt;
	return k;
}

int query(int l,int r,int now,int p,int rank) {
	if (l==r) return l;
	int k=tree[p].cnt-tree[now].cnt;
	if (rank>=k) return query(l,(l+r)/2,tree[now].l,tree[p].l,rank);
	    else return query((l+r)/2+1,r,tree[now].r,tree[p].r,rank-k);
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j;
		scanf("%d%d",&n,&m);
		root[0]=build(1,n);
		num=0;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i].val);
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		for (i=1;i<=n;i++) {
			r[a[i].id]=i;
		}
		int l;
		for (i=1;i<=n;i++) {
			root[i]=update(root[i-1],i-1,i,pos,a[i]);
		} 
	}
	return 0;
}

