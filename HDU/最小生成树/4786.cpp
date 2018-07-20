#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=100005;
int f[maxn];

struct Edge {
	int from,to,c;
};
Edge a[maxn];

bool cmp(Edge a,Edge b) {
	return a.c<b.c;
}

int find(int a) {
	if (f[a]==a) return a; else {
		f[a]=find(f[a]);
		return f[a];
	}
}

int kruskal(int n,int m,int b) {
	int i;
	for (i=1;i<=n;i++) f[i]=i;
	ll sum=0,num=1;
	if (b) {
		i=0;
	while (num<n&&i<m) {
		i++;
		int fa=find(a[i].from),fb=find(a[i].to);
		if (fa!=fb) {
			f[fa]=fb;
			num++;
			sum+=a[i].c;
		}
	}
	}
	else {
		i=m+1;
	while (num<n&&i>0) {
		i--;
		int fa=find(a[i].from),fb=find(a[i].to);
		if (fa!=fb) {
			f[fa]=fb;
			num++;
			sum+=a[i].c;
		}
	}
	}
	if (num==n) return sum; else return -1;
}

int main() {
	int t,n,m,i,j,cnt=0;
	scanf("%d",&t);
	while (t--) {
		cnt++;
		printf("Case #%d: ",cnt);
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;i++) {
			scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].c);
		}
		sort(a+1,a+m+1,cmp);
		int min=kruskal(n,m,1),max=kruskal(n,m,0);
		int a=1,b=2,flag=0;
		while (a<=100000) {
			if (min<=a&&a<=max) {
				flag=1;
				break;
			} 
			int c=a+b;
			a=b;
			b=c;
		}
		if (flag) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
