#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=1000005;
int f[2*maxn],r[maxn];

int find(int now) {
	if (f[now]==now) return now; else {
		int t=f[now];
		f[now]=find(f[now]);
		r[now]=(r[now]+r[t])%2;
		return f[now];
	}
}

int main() {
	int i,j,a,b,n,m,num=0;
	scanf("%d%d",&n,&m);
	memset(r,0,sizeof(r));
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&j,&a,&b);
		if (j==0) {
			int fa=find(a);
         	int fb=find(b);
            if (fa==fb)  {
			    if ((r[a]+r[b])%2==0) {
                  	cout << "NO";
                	return 0;
                }
			} else {
             	f[fb]=fa;
             	r[fb]=r[b]+r[a]+1;
             	r[fb]%=2;
            }
		} else {
			int fa=find(a);
			int fb=find(b);
			if (fa==fb) {
				if ((r[a]+r[b])%2) {
					cout << "NO";
					return 0;
				}
			} else {
				f[fb]=fa;
				r[fb]=r[a]+r[b];
             	r[fb]%=2;
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
NO*/
/*
5 6
0 1 5
1 2 5
1 4 1
1 3 3
1 3 5
0 3 4
YES*/
