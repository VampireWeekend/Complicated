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
const int maxn=205,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const db eps=1e-6;
int dfn[maxn]; 
db r[maxn][maxn],a[maxn];
int m,num;

bool bfs(int n,int s,int t) {
	int i;num=0;
	queue<int> q; 
	q.push(s);
	memset(dfn,-1,sizeof(dfn));
	dfn[s]=num++;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (i=1;i<=m;i++) {
			int to=(now+i)%n; 
			if (dfn[to]==-1&&a[i]>eps) {
				dfn[to]=num++;
				q.push(to);
			}
		}
	}
	return dfn[t]!=-1||dfn[n-t]!=-1;
}

bool gauss(int size) {    
    int i,j,k;
    for (i=0;i<size;i++) {
    	for (j=0;j<=size;j++) printf("%.2lf ",r[i][j]); 
    	printf("\n");
    } 
    for (i=0;i<size;i++) {    
        k=i;    
        for (j=i+1;j<size;j++) 
            if (fabs(r[j][i])>fabs(r[k][i])) k=j;        
        if (fabs(r[k][i])<eps) return false;
        for (j=i;j<=size;j++)   
            swap(r[k][j],r[i][j]);  
        db t=r[i][i];  
        for (j=i;j<=size;j++)   
            r[i][j]/=t;  
        for (j=0;j<size;j++) {    
            if (i==j) continue;    
            db t=r[j][i];   
            for (k=i;k<=size;k++) {    
                r[j][k]-=t*r[i][k];    
            }    
        }
    }  
    return true;  
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,x,y,d,i,j;
		scanf("%d%d%d%d%d",&n,&m,&y,&x,&d);
		for (i=1;i<=m;i++) {
			scanf("%lf",&a[i]);
			a[i]/=100.0;
		}
		if (x==y) {
			printf("0.00\n");continue;
		}
		mem0(dfn);
		n=2*(n-1);
		if (d==1) x=n-x;
		if (!bfs(n,x,y)) {
			printf("Impossible !\n");continue;
		}
		mem0(r);
		for (i=0;i<n;i++) printf("%d ",dfn[i]);
		printf("\n");
		for (i=0;i<n;i++) {
			if (dfn[i]==-1) continue;
			r[dfn[i]][dfn[i]]=1.0;
			if (i==y||i==n-y) continue;
			for (j=1;j<=m;j++) {
				if (dfn[(i+j)%n]==-1||a[j]<eps) continue;
				r[dfn[i]][dfn[(i+j)%n]]-=a[j];
				r[dfn[i]][num]+=a[j]*j;
			}
		}
		if (!gauss(num)) {
			printf("Impossible !\n");
		} else {
			printf("%.2lf\n",r[dfn[x]][num]);
		}
	}
	return 0;
}
