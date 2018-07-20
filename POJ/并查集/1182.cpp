#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=50005;
int f[maxn],r[maxn];

int find(int now) {
	if (f[now]==now) return now; else {
		int fa=f[now];
		f[now]=find(f[now]);
		r[now]=r[now]+r[fa];
		r[now]%=3;
		return f[now];
	}
}

int main() {
	int n,k,i,j,d,x,y,ans=0;
	scanf("%d%d",&n,&k);
	memset(r,0,sizeof(r));
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=k;i++) {
		scanf("%d%d%d",&d,&x,&y);
		if ((x==y&&d==2)||(x>n)||(y>n)) cout << i << ' '; else{	
	    	int fa=find(x);
	    	int fb=find(y);
	    	if (fa==fb) {
		    	if (d==1) {
		    		if (r[x]!=r[y]) cout << i << ' '; 
		    	}
		    	else {
				    if ((r[y]+3-r[x])%3!=1) cout << i << ' ';
		    	}
    		} else {
    			f[fb]=fa;
    		    r[fb]=3-r[y]+r[x]+d-1;
    		    r[fb]%=3;
    		}
	    }
	}
	return 0;
}


/*
6 7
2 1 4
1 3 5
2 5 4
1 1 3
1 3 5
2 2 1
2 4 2

*/

