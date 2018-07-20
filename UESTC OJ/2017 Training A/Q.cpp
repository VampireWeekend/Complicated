#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;
typedef long long ll;
const int maxn=2000; 
ll f[maxn][maxn];
int N,M;
char s[10];

int lowbit(int v) {
	return (v&(-v));
}

void update (int n,int m,ll c) {
    int i=n,j=m;
	for (i=n;i<=N;i+=lowbit(i))
	    for (j=m;j<=N;j+=lowbit(j))
	        f[i][j]+=c;
}

ll findsum(int n,int m) {
	int i=n,j=m;
	ll sum=0;
	for (i=n;i>0;i-=lowbit(i))
	    for (j=m;j>0;j-=lowbit(j))
	        sum+=f[i][j];
	return sum;
}

int main() {
	int n,i,t,q;
	int x1,x2,y1,y2;
	char c;
	scanf("%d",&t);
	N=2000;
	for(q=1;q<=t;q++) {
		memset(f,0,sizeof(f));
		scanf("%d",&M);
		for (i=1;i<=M;i++) {
			scanf("%s",s);
			if (s[0]=='C') {
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				update(x1,y1,1);
				update(x2+1,y2+1,1);
				update(x1,y2+1,-1);
				update(x2+1,y1,-1);
			} else {
				scanf("%d%d",&x1,&y1);
				ll s=findsum(x1,y1);
				if (s%2) printf("1\n"); else printf("0\n");
			}
		}
	}
	return 0;
}
