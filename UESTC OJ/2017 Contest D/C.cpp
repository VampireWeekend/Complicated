#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=100;
int mark['z'+1],x['z'+1],y['z'+1];
char a[7][7];
char s[1000005];

int main() {
	int n,t,q;
	char c;
	scanf("%d",&t);
	scanf("%c",&c);
	for (q=1;q<=t;q++) {
		printf("Case %d: ",q);
		int num=0,i=1,j=1;
		scanf("%c",&c);
		memset(mark,0,sizeof(mark));
		while (c!='\n') {
			if (!((c<='z'&&c>='a')||(c<='Z'&&c>='A'))){
				scanf("%c",&c);
				continue;
			} 
			if (c<='z'&&c>='a') c=(char)(c-'a'+'A');
			if (!mark[c]) {
				mark[c]=1;
				a[i][j]=c;
				j++;
				num++;
				if (j==6) {
					i++;j=1;
				}
			}
			scanf("%c",&c);
		}
		for (c='A';c<='Z';c++) {
			if (c=='J') continue;
			if (!mark[c]) {
				a[i][j]=c;
				j++;
			    if (j==6) {
					i++;j=1;
			    }
			}
		}
		for (i=1;i<=5;i++) {
			a[i][6]=a[i][1];
		}
		for (i=1;i<=5;i++) {
			a[6][i]=a[1][i];
		}
		for (i=1;i<=5;i++) {
			for (j=1;j<=5;j++) {
				c=a[i][j];
		//		cout << c;
				x[c]=i;
				y[c]=j;
			}
		//	cout << '\n';
		}
		cin.getline(s,1000000);
		int top=0,len=strlen(s);
		char repeat='A',c1,c2;
		while (top<len) {
			if (!((s[top]<='z'&&s[top]>='a')||(s[top]<='Z'&&s[top]>='A'))){
				top++;
				continue;
			} 
			if (len-1==top) {
				c1=s[top];
				if (c1<='z'&&c1>='a') c1=(char)(c1-'a'+'A');
				while (repeat==c1) {
				    repeat=(char)(repeat+1);
				    if (repeat>'Z') repeat='A';
				    if (repeat=='J') repeat='K';
			    }
			    c2=repeat;
				top++;
			} else {
				c1=s[top];
				if (c1<='z'&&c1>='a') c1=(char)(c1-'a'+'A');
				top++;
				while ((!((s[top]<='z'&&s[top]>='a')||(s[top]<='Z'&&s[top]>='A')))&&top<len)
				    top++;
					if (top<len) c2=s[top]; else c2=repeat;
					if (c2<='z'&&c2>='a') c2=(char)(c2-'a'+'A');
					if (c1==c2) {
						while (repeat==c1) {
				        	repeat=(char)(repeat+1);
				        	if (repeat>'Z') repeat='A';
				        	if (repeat=='J') repeat='K';
			         	}
			        	c2=repeat;
			        	repeat=(char)(repeat+1);
			        	if (repeat>'Z') repeat='A';
				        if (repeat=='J') repeat='K';
					} else top++;
			} 
			if (x[c1]==x[c2]) {
				printf("%c%c",a[x[c1]][y[c1]+1],a[x[c2]][y[c2]+1]);
			} else if (y[c1]==y[c2]) {
				printf("%c%c",a[x[c1]+1][y[c1]],a[x[c2]+1][y[c2]]);
			} else 
			    printf("%c%c",a[x[c1]][y[c2]],a[x[c2]][y[c1]]);
		}
		printf("\n");
	}
	return 0;
}
