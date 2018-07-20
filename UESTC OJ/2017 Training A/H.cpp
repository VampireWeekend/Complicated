#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=70005;
const int maxk=7;
const int treenum=maxk*(maxk+1)/2;
struct Tree {
	int l,r,lc,rc;
	ll max[treenum];
};
Tree tree[maxn*3];
int num;
ll a[maxn];
int b[maxk+1][maxk+1];

ll max(ll a,ll b) {
	if (a>b) return a; else return b;
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	if (l==r) {
		memset(tree[now].max,-0x2,sizeof(tree[now].max));
		scanf("%lld",&a[l]);
		for (int i=1;i<=maxk;i++) 
		    tree[now].max[b[i][l%i]]=a[l];
	} else {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		for (int i=0;i<treenum;i++) 
			tree[now].max[i]=max(tree[tree[now].lc].max[i],tree[tree[now].rc].max[i]);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max[3] << endl;
}

void update(int now,int pos,int c) {
	if (pos==tree[now].l&&pos==tree[now].r) {
		for (int i=1;i<=maxk;i++) 
		    tree[now].max[b[i][pos%i]]+=c;
	} else {
		if (pos<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,pos,c);
		if (pos>(tree[now].l+tree[now].r)/2) 
		    update(tree[now].rc,pos,c);
		for (int i=1;i<=maxk;i++) 
		    tree[now].max[b[i][pos%i]]=max(tree[tree[now].lc].max[b[i][pos%i]],tree[tree[now].rc].max[b[i][pos%i]]);
    }
}

ll findmax(int now,int l,int r,int sn) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max[sn] << endl;
	if (l<=tree[now].l&&r>=tree[now].r) {
		return tree[now].max[sn];
	} else if (r<=tree[tree[now].lc].r) return findmax(tree[now].lc,l,r,sn); else
	   if (l>=tree[tree[now].rc].l) return findmax(tree[now].rc,l,r,sn); else 
         	return max(findmax(tree[now].lc,l,r,sn),findmax(tree[now].rc,l,r,sn));
}

int main() {
	int i,j,n,m,c,x,y;
	scanf("%d",&n);
	num=0;
	for (i=1;i<=maxk;i++) 
		for (j=0;j<i;j++)
	    	b[i][j]=num++;
	num=1;
	build(1,1,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&c);
		if (x==1) {
			if (c<=maxk)
			    printf("%lld\n",findmax(1,y,n,b[c][y%c]));
		    else {
		    	ll ans=-0x3f3f3f3f3f;
		    	for (j=y;j<=n;j+=c) 
		    	    ans=max(ans,a[j]);
		    	printf("%lld\n",ans);
		    }
		}
		else {
			a[y]+=c;
		    update(1,y,c);
		}
	}
	return 0;
}
/*
10
1 6 1 4 9 4 8 2 8 5
10
1 3 3
0 5 4
0 3 8
1 2 5
1 4 8
1 7 5
1 3 6
0 1 2
1 5 3
1 4 9
*/
