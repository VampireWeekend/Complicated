#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1000005;
int f[2*maxn];

int find(int now) {
	if (f[now]==now) return now; else {
		f[now]=find(f[now]);
		return f[now];
	}
}

int main() {
	int i,j,k,l,n,m,num=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n*2;i++) f[i]=i;
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&j,&k,&l);
		if (j==0) {
			int fa=find(k);
			int fb=find(l);
			int fc=find(k+n);
			int fd=find(l+n);
			if (fa==fb&&fa!=fd&&fb!=fc) {
				cout << "NO" << endl;
				return 0;
			}
			if (fa!=fd) f[fd]=fa;
			if (fb!=fc) f[fc]=fb;
		} else {
			int fa=find(k);
			int fb=find(l);
			int fc=find(k+n);
			int fd=find(l+n);
			if (fa!=fb) f[fa]=fb;
            if (fa==fd||fb==fc) {
            	cout << "NO" << endl;
            	return 0;
            }
		}
	}
	cout << "YES" << endl;
	return 0;
}

/*
6 6
1 1 2
1 4 5
1 3 6
0 1 6
0 3 4
0 1 5

*/
