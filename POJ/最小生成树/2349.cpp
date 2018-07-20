#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <cmath>
using namespace std;
const int maxn=505,maxk=250000;
const int inf=0x3f3f3f3f;
int x[maxn],y[maxn],f[maxn];
int from[maxk],to[maxk];
double edge[maxk],tree[maxn];

double sqr(int x) {
	return (double)x*(double)x;
}

void qsort(int l,int r)
{
	int i=l;
	int j=r;
	double mid=edge[(l+r)/2];
	while (i<j) {
		while (edge[i]<mid) i++;
		while (mid<edge[j]) j--;
		if (i<=j) {
			double z=edge[i];edge[i]=edge[j];edge[j]=z;
			int zz=from[i];from[i]=from[j];from[j]=zz;
			zz=to[i];to[i]=to[j];to[j]=zz;
			i++;j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r); 
}

int find(int now) {
    if (f[now]==now) return now; else {
    	int t=find(f[now]);
    	f[now]=t;
    	return t;
    }	
}

void update(int now,int q) {
	f[now]=q;
}

int main() {
	int i,j,n,s,p,t,top;
	scanf("%d",&n);
	for (t=1;t<=n;t++) {
		top=0;
		scanf("%d%d",&s,&p);
		for (i=1;i<=p;i++) {
			scanf("%d%d",&x[i],&y[i]);
			for (j=1;j<=i-1;j++) {
				double d=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
				top++;
				edge[top]=d;from[top]=i;to[top]=j;
			}
			f[i]=i;
		}
		qsort(1,top);
		//kruskal
		int sum=0;
		for (i=1;i<=top;i++) {
			int fx=find(from[i]),fy=find(to[i]);
			if (fx!=fy) {
				update(fx,fy);
				sum++;
				tree[sum]=edge[i];
				if (sum>=p-1) {
					j=i;
					break;
				}
			}		
		}
		printf("%.2lf\n",tree[p-s+1]);
	}
	return 0;
}
