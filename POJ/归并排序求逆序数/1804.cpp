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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn];
int ans;

void merge(int l,int r) {
	if (l==r) return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	int i,h1,h2,k;
	h1=k=l;h2=mid+1;
	while (h1<=mid&&h2<=r) {
		if (a[h1]>a[h2]) b[k++]=a[h2++],ans+=mid-h1+1; else b[k++]=a[h1++];
	}
	for (i=h1;i<=mid;i++) b[k++]=a[i];
	for (i=h2;i<=r;i++) b[k++]=a[i];
	for (i=l;i<=r;i++) a[i]=b[i];
}

int main() {
	int cas,g=0;
	scanf("%d",&cas);
	while (cas--) {
		g++;
		int n,i,j;
		scanf("%d",&n);
		for (i=1;i<=n;i++) 
			scanf("%d",&a[i]);
		ans=0;
		merge(1,n);
		printf("Scenario #%d:\n%d\n\n",g,ans);
	}
	return 0;
}

