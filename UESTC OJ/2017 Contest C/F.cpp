#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int num[10];
char s[10][16];
string s1[10];
char a[10][100],b[15][100];

int main() {
	s1[0]="**** ** ** ****";
	s1[1]="  *  *  *  *  *";
	s1[2]="***  *****  ***";
	s1[3]="***  ****  ****";
	s1[4]="* ** ****  *  *";
	s1[5]="****  ***  ****";
	s1[6]="****  **** ****";
	s1[7]="***  *  *  *  *";
	s1[8]="**** ***** ****";
	s1[9]="**** ****  ****";
	int i,j,m,k,cnt;
	for (i=0;i<=9;i++) {
		for (j=0;j<=14;j++) {
			s[i][j]=s1[i][j];
		} 
	}
	char c;
	for (i=1;i<=5;i++) {
		cin.getline(a[i],100);
	}
	int len=strlen(a[1]);
	m=(len+1)/4;
	for (i=1;i<=5;i++) {	
		for (k=1;k<=m;k++) {
			for (j=0;j<3;j++) {
			    if (a[i][(k-1)*4+j]=='*'||a[i][(k-1)*4+j]==' ')
				    b[k][(i-1)*3+j]=a[i][(k-1)*4+j];
				else b[k][(i-1)*3+j]=' ';
	    	}
		}
	}
	int sum=0;
	for (i=1;i<=m;i++) {
		int now=-1;
		for (j=0;j<=9;j++) {
			int flag=1;
			for (k=0;k<=14;k++) if (b[i][k]!=s[j][k]) flag=0;
			if (flag) now=j;
		}
		if (now==-1) {
			cout << "BOOM!!" << endl;
			return 0;
		} else sum=sum*10+now;
	}
	if (sum%6==0) cout << "BEER!!"; else cout << "BOOM!!";
	return 0;
}
