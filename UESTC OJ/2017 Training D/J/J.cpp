#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=362885;
int p[10],f[maxn][12],step[maxn],a[10];
int dir[10][10];
char s[10];
//康托展开 
int kanter(int *k) {
	int sum=0,i,j;
	for (i=9;i>=1;i--) {
		int r=0;
		for (j=i+1;j<=9;j++) 
		    if (*(k+i)>*(k+j)) r++;
		sum+=r*p[9-i];
	}
	return sum;
}

int main() {
	int i,j,n;
	p[0]=1;
	memset(dir,0,sizeof(dir));
	dir[1][1]=2;dir[1][2]=4;         // //dir数组记录搜索方向,dir[i][j]=k表示交换第i个和第k个数  
	dir[3][1]=2;dir[3][2]=6;
	dir[7][1]=8;dir[7][2]=4;
	dir[9][1]=6;dir[9][2]=8;
	dir[2][1]=3;dir[2][2]=5;dir[2][3]=1;
	dir[4][1]=1;dir[4][2]=5;dir[4][3]=7;
	dir[6][1]=3;dir[6][2]=5;dir[6][3]=9;
	dir[8][1]=7;dir[8][2]=5;dir[8][3]=9;
	dir[5][1]=2;dir[5][2]=4;dir[5][3]=6;dir[5][4]=8;
	for (i=1;i<=9;i++) {
		p[i]=p[i-1]*i;
		f[0][i]=i;
	}
	f[0][0]=kanter(&f[0][0]);
	f[0][10]=9;
	scanf("%d",&n);
	int head=0,tail=1,k,l;
	memset(step,-1,sizeof(step));
	step[f[0][0]]=0;
	while (head<tail) {
		int pos=f[head][10];
		k=1;
		while ((l=dir[pos][k])!=0) {
			for (i=1;i<=9;i++) {
				f[tail][i]=f[head][i];
			}
			f[tail][pos]=f[tail][l];
			f[tail][l]=9;
			int hash=kanter(&f[tail][0]);
			if (step[hash]==-1) {
				f[tail][10]=l;
				f[tail][0]=hash;
				step[hash]=step[f[head][0]]+1;
				tail++;
			}
			k++;
		}
		head++;
	}
	char c;
	for (i=1;i<=n;i++) {
	    for (j=1;j<=9;j++) {
	    	scanf("%c",&c);
	    	while (c!='x'&&!(c>='0'&&c<='9')) 
			    scanf("%c",&c);
	    	if (c=='x') a[j]=9; else a[j]=c-'0';
	    }
	    int d=kanter(&a[0]);
		printf("%d\n",step[d]);
	}
	return 0;
}
