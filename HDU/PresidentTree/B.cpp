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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=505,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int ans[maxn][5];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j;
		scanf("%d%d",&n,&m);
		mem0(ans);
		char p,q;
		for (i=1;i<=m;i++) {
			for (j=1;j<=n;j++) {
				scanf("%c",&q);
				while (!(q>='A'&&q<='Z')) scanf("%c",&q);
		    	scanf("%c",&p);
		    	while (!(p>='A'&&p<='Z')) scanf("%c",&p);
		    	if (p=='F') {
		    		ans[j][q-'A']=2;
		    	} else {
		    		ans[j][q-'A']=1;
		    	}
			}
		}
		for (i=1;i<=n;i++) {
			int cnt=0,l=-1,flag=0;
			for (j=0;j<4;j++) {
				if (ans[i][j]==2) cnt++; else
				    if (ans[i][j]==1) l=j,flag=1;
			}
			if (flag) {
				if (i==n) printf("%c\n",(char)(l+'A')); else
				printf("%c ",(char)(l+'A'));
			} else if (cnt==3) {
				for (j=0;j<4;j++) {
					if (ans[i][j]!=2) {
						if (i==n) printf("%c\n",(char)(j+'A')); else
			         	printf("%c ",(char)(j+'A'));
					}
				}
			} else {
				if (i==n) printf("?\n"); else
			         	printf("? ");
			}
		}
	}
	return 0;
}

