//求最大子矩阵面积 
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1005;
int up[maxn],l[maxn],r[maxn];     //对于一个点，可以向上、向左、向右延伸
                                  //记录最大高度、取最大高度时的左右延伸坐标，S=max(h*(r-l-1)) 
int t,i,j,ans,q,n,m;
char s[maxn];

int max(int a,int b){
	if (a>b) return a; else return b;
}

void dp() {
	int i,j;
	for (i=1;i<=n;i++) 
		if (up[i]) 
			for (j=i-1;;j=l[j]) 
				if (up[j]<up[i]) {
					l[i]=j;
					break;
				}
	for (i=n;i>=1;i--) 
		if (up[i]) 
			for (j=i+1;;j=r[j]) 
				if (up[j]<up[i]) {
					r[i]=j;
					break;
				}
	for (i=1;i<=n;i++) 
		if (up[i]) 
		    ans=max(ans,up[i]*(r[i]-l[i]-1));
}

int main() {
	scanf("%d",&t);
	for (q=1;q<=t;q++) {
		ans=0;
		cin >> m >> n;	
		for (j=1;j<=n;j++) up[j]=0;
		for (i=1;i<=m;i++) {
			for (j=1;j<=n;j++)  {
		    	scanf("%s",s);
		    	if (s[0]=='F') up[j]++; else up[j]=0;
	        }
	        l[0]=r[n+1]=l[n+1]=r[0]=-1;
	        dp();
		} 	
		cout << ans*3 << endl;
	}
	return 0;
}

/*
2
4 5
R F F R F
F F F F F
R F R F F
F F F F F

5 6
R F F F F F
F F F F F F
R R R F F F
F F F F F F
F F F F F F
*/
