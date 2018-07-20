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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int x[maxn],y[maxn];

bool check(int m,int mid) {
	int i,j;
	int mn,mx,MN,MX;
	mn=MN=inf;mx=MX=-inf;
	for (i=1;i<=m;i++) {
		if (y[i]-x[i]<=mid) continue;
	    mn=min(mn,x[i]+y[i]+mid);  
        mx=max(mx,x[i]+y[i]-mid);  
        MN=min(MN,y[i]-x[i]+mid);  
        MX=max(MX,y[i]-x[i]-mid);  
	}
	if (mn==mx&&MN==MX&&(mn+MN)%2==1) return false;
	if (mx>mn||MX>MN) return false;
	return true;
}

int main() {
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF) {
		int i,l,r,mid,ans;
		for (i=1;i<=m;i++) {
			scanf("%d%d",&x[i],&y[i]);
			if (x[i]>y[i]) swap(x[i],y[i]);
		}
		l=0;r=n;ans=n;
		while (l<=r) {
			mid=(l+r)/2;
			if (check(m,mid)) ans=mid,r=mid-1; else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
