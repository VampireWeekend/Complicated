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
typedef double db;
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
int c[maxn][maxn]; 
db ans[maxn],r[maxn][maxn];

void gauss(int size) {
	int i,j,k;
	for (i=0;i<size;i++) {
	/*	for (k=0;k<size;k++) {
			for (j=0;j<=size;j++) {
				cout << r[k][j] << ' ';
			}
			cout << "\n";
		}
		cout << '\n';*/
		k=i;
		for (j=i+1;j<size;j++) {     //找最大的列主元 
			if (fabs(r[j][i])>fabs(r[k][i])) k=j;
		}
		if (fabs(r[k][i])<1e-9) continue; 
		for (j=i;j<=size;j++) {
			db z=r[k][j];r[k][j]=r[i][j];r[i][j]=z;
		}
		for (j=0;j<size;j++) {
			if (i==j) continue;
			if (fabs(r[j][i])<1e-9) continue;
			db l=r[j][i]/r[i][i];
			for (k=i;k<=size;k++) {
				r[j][k]-=l*r[i][k];
			}
		}
	}
/*	for (i=0;i<size;i++) {
			for (j=0;j<=size;j++) {
				cout << r[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << '\n';*/
	ans[size-1]=1.0;
	for (i=size-2;i>=0;i--) {
		ans[i]=r[i][size]/r[i][i];
	}
}

int main() {
	int m,n,i,j,a,b;
	mem0(c);
	c[0][0]=1;
	for (i=1;i<=20;i++) {
		c[i][0]=1;
		for (j=1;j<=i;j++) {
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	scanf("%d%d%d%d",&a,&m,&b,&n);
	while (a!=0||m!=0||b!=0||n!=0) {
		mem0(r);
		r[0][0]=1;
		for (i=1;i<=n*m;i++) {
			for (j=0;j<=i;j++) {
				db z=c[i][j]*pow(a*1.0,j/m)*pow(b*1.0,(i-j)/n);
				r[(j%m)*n+(i-j)%n][i]+=z;
			}
		}
		r[n*m][n*m]=1;
		r[n*m][n*m+1]=1;
		gauss(n*m+1);
		for (i=n*m;i>=0;i--) {
			if (ans[i]<1e-9) ans[i]-=0.5; else ans[i]+=0.5;
			printf("%d ",(int)(ans[i]));
		}
		printf("\n");
		scanf("%d%d%d%d",&a,&m,&b,&n);
	}
	return 0;
}

