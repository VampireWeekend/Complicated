#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100005;
struct Tree {
	int l,r,lc,rc;
	int m0,lm0,rm0,m1,lm1,rm1;
	bool isxor,flag0,flag1;
}; 
Tree tree[3*maxn];
int num;

int max (int a,int b) {
	if (a>b) return a; else return b;
}

int min(int a,int b) {
	if (a>b) return b; else return a;
}

void pushup(int now) {
	int l=tree[now].lc,r=tree[now].rc;
	tree[now].flag0=tree[l].flag0&&tree[r].flag0;
	tree[now].flag1=tree[l].flag1&&tree[r].flag1;
	tree[now].m0=max(tree[l].m0,tree[r].m0);
	tree[now].m0=max(tree[now].m0,tree[l].rm0+tree[r].lm0);
	if (tree[l].flag0)
    	tree[now].lm0=tree[l].r-tree[l].l+1+tree[r].lm0;
        else tree[now].lm0=tree[l].lm0;
    if (tree[r].flag0)
    	tree[now].rm0=tree[r].r-tree[r].l+1+tree[l].rm0;
        else tree[now].rm0=tree[r].rm0;
	tree[now].m1=max(tree[l].m1,tree[r].m1);
	tree[now].m1=max(tree[now].m1,tree[l].rm1+tree[r].lm1);
	if (tree[l].flag1)
    	tree[now].lm1=tree[l].r-tree[l].l+1+tree[r].lm1;
        else tree[now].lm1=tree[l].lm1;
    if (tree[r].flag1)
    	tree[now].rm1=tree[r].r-tree[r].l+1+tree[l].rm1;
        else tree[now].rm1=tree[r].rm1;
}

void ToDoXor(int now) {
	Tree t=tree[now];
	tree[now].flag0=t.flag1;tree[now].flag1=t.flag0;
	tree[now].m0=t.m1;      tree[now].m1=t.m0;
	tree[now].lm0=t.lm1;    tree[now].lm1=t.lm0;
	tree[now].rm0=t.rm1;    tree[now].rm1=t.rm0;
}

void pushdown(int now) {
	if (tree[now].isxor==0) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].isxor=tree[l].isxor^tree[now].isxor;
	tree[r].isxor=tree[r].isxor^tree[now].isxor;
	tree[now].isxor=0;
	ToDoXor(l);
	ToDoXor(r);
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
		pushup(now);
	} else {
		int x;
		scanf("%d",&x);
		if (x) {
			tree[now].flag1=1;
			tree[now].lm1=tree[now].rm1=tree[now].m1=1;
			tree[now].lm0=tree[now].rm0=tree[now].m0=0;
			tree[now].flag0=0;
		} else {
			tree[now].flag1=0;
			tree[now].lm1=tree[now].rm1=tree[now].m1=0;
			tree[now].lm0=tree[now].rm0=tree[now].m0=1;
			tree[now].flag0=1;
		}
	}
}

void update (int now,int l,int r) {
//cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].lm1 << ' ' << tree[now].rm1 << ' ' << tree[now].m1 << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].isxor=tree[now].isxor^1;
		ToDoXor(now);
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r);
	    pushup(now);
	}
//cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].lm1 << ' ' << tree[now].rm1 << ' ' << tree[now].m1 << endl;
}

Tree findm1(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].lm1 << ' ' << tree[now].rm1 << ' ' << tree[now].m1 << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now];
	} else {
		pushdown(now);
	    if (r<=tree[tree[now].lc].r) return findm1(tree[now].lc,l,r); 
        	else if (l>=tree[tree[now].rc].l) return findm1(tree[now].rc,l,r); 
        	else 
			{	
	        	Tree t,t1,t2;
		        t1=findm1(tree[now].lc,l,r);
	    	    t2=findm1(tree[now].rc,l,r);
	    	    t=tree[now];
	    	    t.l=t1.l;
	    	    t.r=t2.r;
            	t.flag1=t1.flag1&&t2.flag1;
             	t.m1=max(t1.m1,t2.m1);
             	t.m1=max(t.m1,t1.rm1+t2.lm1);
            	if (t1.flag1)
                	t.lm1=t1.r-t1.l+1+t2.lm1;
                    else t.lm1=t1.lm1;
                if (t2.flag1)
                	t.rm1=t2.r-t2.l+1+t1.rm1;
                    else t.rm1=t2.rm1;
  //              cout << ' ' << t.l << ' ' << t.r << ' ' << t.lm1 << ' ' << t.rm1 << ' ' << t.m1 << endl;
                return t;
	        }
	}
}

int main() {
	int n,m,i,k,l,r;
	scanf("%d",&n);
	num=1;
	build(1,1,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&k,&l,&r);
		if (k) 
		    update(1,l,r); 
		else {
			Tree t=findm1(1,l,r);
			printf("%d\n",t.m1);
		}
	}
	return 0;
}
/*
8
1 0 1 1 0 1 0 1
100000
1 3 4
1 2 5
0 1 5

*/
