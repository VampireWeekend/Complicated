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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];
int num;

struct Tree{
	int l,r,lc,rc,min;
};
Tree tree[maxn*4];

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
		tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
	} else tree[now].min=a[l];
}

int findmin (int now,int l,int r,int val) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l==tree[now].r) {
		return tree[now].l;
	} else {
		int f;
		if (l<=(tree[now].l+tree[now].r)/2&&tree[tree[now].lc].min<=val) {
			f=findmin(tree[now].lc,l,r,val);
			if (f!=-1) return f;
		}   
		if (r>(tree[now].l+tree[now].r)/2&&tree[tree[now].rc].min<=val) {
			f=findmin(tree[now].rc,l,r,val);
			if (f!=-1) return f;
		}
		return -1;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j,l,r;
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		num=1;
		build(1,1,n);
		scanf("%d",&m);
		for (i=1;i<=m;i++) {
			scanf("%d%d",&l,&r);
			int ans=a[l];
			l++;
			while (l<=r) {
				int p=findmin(1,l,r,ans);
				if (p==-1) break;
				ans%=a[p];
				l=p+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

