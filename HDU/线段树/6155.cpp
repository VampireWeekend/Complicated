#include <cstdio>
#include <string.h>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define size 3
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
char s[maxn];
int num;

struct Matrix {  
    ll a[size][size];  
};
Matrix m0=(Matrix){1,1,1,0,1,0,0,0,1};
Matrix m1=(Matrix){1,0,0,1,1,1,0,0,1};

void print(Matrix v) {
	int i,j;
	for (i=0;i<size;i++) {  
        for (j=0;j<size;j++) {  
            printf("%lld ",v.a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
  
Matrix operator*(const Matrix &x,const Matrix &y) {  
    int i,j,k;
    Matrix ans;
    for (i=0;i<size-1;i++) {  
        for (j=0;j<size;j++) {  
            ans.a[i][j]=0;  
            for (k=0;k<size;k++) {  
                ans.a[i][j]+=x.a[i][k]*y.a[k][j];  
                ans.a[i][j]%=mod;  
            }  
        }
    }
    ans.a[2][0]=ans.a[2][1]=0;ans.a[2][2]=1;
    return ans;
}

void flip(Matrix &x) {
	for (int i=0;i<size;i++) swap(x.a[i][0],x.a[i][1]);
	for (int i=0;i<size;i++) swap(x.a[0][i],x.a[1][i]);
}

struct Tree {
	int lc,rc,l,r,isxor;
	Matrix sum;
};
Tree tree[4*maxn];

void pushdown(int now) {
	if (tree[now].isxor==0) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].isxor=tree[l].isxor^tree[now].isxor;
	tree[r].isxor=tree[r].isxor^tree[now].isxor;
	flip(tree[l].sum);flip(tree[r].sum);
	tree[now].isxor=0;
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].isxor=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].sum=tree[tree[now].rc].sum*tree[tree[now].lc].sum;
	} else {
	    if (s[l]=='0') tree[now].sum=m0;
		    else tree[now].sum=m1;
	}
}

void update (int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].isxor^=1;
		flip(tree[now].sum);
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r);
		tree[now].sum=tree[tree[now].rc].sum*tree[tree[now].lc].sum;
	}
}

Matrix findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		pushdown(now);
		if (r>(tree[now].l+tree[now].r)/2) {
			Matrix f;
			f=findsum(tree[now].rc,l,r);
			if (l<=(tree[now].l+tree[now].r)/2) 
		        f=f*findsum(tree[now].lc,l,r);
		    return f;
		} else return findsum(tree[now].lc,l,r);
	}
}

bool findval(int now,int pos) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag << endl;
	if (tree[now].l>=pos&&tree[now].r<=pos) {
		return tree[now].isxor^(s[pos]-'0');
	} else {
		pushdown(now);
		if (pos<=(tree[now].l+tree[now].r)/2) 
		    return findval(tree[now].lc,pos);
		if (pos>(tree[now].l+tree[now].r)/2) 
			return findval(tree[now].rc,pos);
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j,l,r,t;
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		num=1;
		build(1,1,n);
		for (i=1;i<=m;i++) {
			scanf("%d%d%d",&t,&l,&r);
			if (t==1) update(1,l,r); else {
				if (l==r) {
					printf("1\n");
					continue;
				}
				Matrix v,t;
				if (findval(1,l)) t=(Matrix){0,0,0,1,0,0,1,0,0};
	        	    else t=(Matrix){1,0,0,0,0,0,1,0,0};
	        	v=findsum(1,l+1,r);
	      //  	print(v);
	        	v=v*t;
	        	ll q=(v.a[0][0]+v.a[1][0])%mod;
	        	printf("%lld\n",q);
			}
		}
	}
	return 0;
}

