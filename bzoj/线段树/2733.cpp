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
int f[maxn],a[maxn],id[maxn];
int lc[maxn*20],rc[maxn*20],sum[maxn*20],root[maxn*20];
char s[20];
int num;

int find(int now) {
	if (f[now]==now) return now; else {
		f[now]=find(f[now]);
		return f[now];
	}
}

void insert(int &k,int l,int r,int val) {
	if (!k) k=++num;
	if (l==r) {
		sum[k]=1;
	} else {
		int mid=(l+r)/2;
		if (val<=mid) insert(lc[k],l,mid,val); else
			insert(rc[k],mid+1,r,val);
		sum[k]=sum[lc[k]]+sum[rc[k]];
	}
}

int query(int now,int l,int r,int k) {
	if (l==r) {
		return l;
	} else {
		int mid=(l+r)/2;
		if (k<=sum[lc[now]]) 
			return query(lc[now],l,mid,k);
		else 
			return query(rc[now],mid+1,r,k-sum[lc[now]]);
	}
}

int merge(int x,int y) {
	if (!x) return y;
	if (!y) return x;
	lc[x]=merge(lc[x],lc[y]);
	rc[x]=merge(rc[x],rc[y]);
	sum[x]=sum[lc[x]]+sum[rc[x]];
	return x;
}

int main() {
	int n,m,i,j,q,x,y;
	num=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=i;
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		int fa=find(x),fb=find(y);
		if (fa!=fb) f[fa]=fb;
	}
	for (i=1;i<=n;i++) {
		insert(root[find(i)],1,n,a[i]);
		id[a[i]]=i;
	}
	scanf("%d",&q);
	for (i=1;i<=q;i++) {
		scanf("%s",s);
		if (s[0]=='Q') {
			scanf("%d%d",&x,&y);
			if (sum[root[find(x)]]<y) {
				printf("-1\n");
				continue;
			}
			int ans=query(root[find(x)],1,n,y);
			printf("%d\n",id[ans]);
		} else {
			scanf("%d%d",&x,&y);
			int fa=find(x),fb=find(y);
			if (fa!=fb) {
				f[fa]=fb;
				root[fb]=merge(root[fa],root[fb]);
			}
		}
	}
	return 0;
}
