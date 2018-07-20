#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;
int a[maxn],b[maxn],c[maxn];
int num,n;

struct Tree{
	int l,t;
	db g;
};
Tree f[maxn];

struct query {
	int p,a,b,id,l[2];
	db g[2];
	bool operator< (const query &x) const {
		return id<x.id;
	}
};
query q[maxn],tem[maxn];

bool cmp(int x,int y) {
	return q[x].a<q[y].a || (q[x].a==q[y].a&&q[x].id<q[y].id);
}

int lowbit(int x) {
	return x&(-x);
}

Tree gettree(int tt) {
	Tree ans;
	ans.l=0;ans.g=0.0;
	for (int t=tt;t;t-=lowbit(t)) {
		if (f[t].t==num) {
			if (f[t].l>ans.l) {
				ans.g=f[t].g;ans.l=f[t].l;
			} else if (f[t].l==ans.l) ans.g+=f[t].g;
		}
	}
	return ans;
}

void update(int tt,int l,db g) {
	int t=tt;
	for (int t=tt;t<=n;t+=lowbit(t)) {
		if (f[t].t!=num) {
			f[t].t=num;
		    f[t].g=g;f[t].l=l;
		} else {
			if (f[t].l==l) f[t].g+=g; else 
			    if (l>f[t].l) f[t].g=g,f[t].l=l;
		}
	}
}

void cdq(int l,int r,int p) {
	if (l==r) {
		if (q[l].l[p] < 1) 
			q[l].l[p] = 1, q[l].g[p] = 1.0;
		return;
	}
	int mid=(l+r)/2;
	memcpy(tem+l,q+l,sizeof(query)*(r-l+1));
	int h=l,t=mid+1;
    for (int i=l;i<=r;i++)  (tem[i].p<=mid?q[h++]:q[t++])=tem[i];
	cdq(l,mid,p);
	num++;
	h=l,t=mid+1;
	for (int i=mid+1;i<=r;i++)
    {
        while (h<=mid&&q[h].id<q[i].id) 
		    update(q[h].b,q[h].l[p],q[h].g[p]),h++;
        Tree now=gettree(q[i].b);
        if (!now.l) continue;
        if (now.l+1>q[i].l[p])  q[i].l[p]=now.l+1,q[i].g[p]=now.g;
            else if (now.l+1==q[i].l[p]) q[i].g[p]+=now.g;
    }
	cdq(mid+1,r,p);
	merge(q+l,q+mid+1,q+mid+1,q+r+1,tem+l);
	memcpy(q+l,tem+l,sizeof(query)*(r-l+1));
}

int main() {
	int i,j;
	num=0;
	scanf("%d",&n);
	mem0(f);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		q[i].a=a[i];q[i].b=b[i];q[i].id=c[i]=i;
		q[i].l[0]=q[i].l[1]=q[i].g[0]=q[i].g[1]=0;
	}
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	int t1=unique(a+1,a+n+1)-a-1,t2=unique(b+1,b+n+1)-b-1;
	for (i=1;i<=n;i++) {
		q[i].a=t1-(lower_bound(a+1,a+t1+1,q[i].a)-a)+1;
		q[i].b=t2-(lower_bound(b+1,b+t2+1,q[i].b)-b)+1;
	}
	sort(c + 1, c + n + 1, cmp);
	for (i = 1; i <= n; i++) q[c[i]].p = i;
	cdq(1,n,0);
	for (i=1;i<=n;i++) {
		q[i].p=n-q[i].p+1;
		q[i].id=n-q[i].id+1;
		q[i].a=t1-q[i].a+1;
		q[i].b=t2-q[i].b+1;
	}
	reverse(q+1,q+n+1);
	cdq(1,n,1);
	reverse(q+1,q+n+1);
/*	for (i=1;i<=n;i++) {
		cout << q[i].l[0] << ' ' << q[i].l[1] << ' ';
		cout << q[i].g[0] << ' ' << q[i].g[1] << endl;
	}*/
	int ml=-1;db sums=0.0;
	for (i=1;i<=n;i++) {
		if (q[i].l[0]+q[i].l[1]>ml) {
			ml=q[i].l[0]+q[i].l[1];
			sums=0.0;
		}
		if (q[i].l[1]==1&&q[i].l[0]+q[i].l[1]==ml) 
		    sums+=q[i].g[0]*q[i].g[1];
	}
	printf("%d\n",ml-1);
	for (i=1;i<=n;i++) {
		if (q[i].l[0]+q[i].l[1]==ml) {
			printf("%.5f",q[i].g[0]*q[i].g[1]/sums);
		} else printf("0.00000");
		if (i!=n) printf(" ");
	}
//	system("pause");
	return 0;
}

/*
4
3 30
4 40
6 60
3 30
*/
