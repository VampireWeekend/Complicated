#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=105;
struct info{
	string name;
	int c;
};
info a[maxn];

bool cmp(info a,info b) {
	return (a.c>b.c)||(a.c==b.c&&a.name<b.name);
}

int main() {
	int t,q,i,n,j;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			string s,t;
			cin >> s;
			a[i].name=s.substr(0,s.length()-1);
			cin >> s;
			t=s;
			int p,cnt=0;
			while ((p=t.find('-'))!=-1) {
				cnt++;
				t=t.substr(p+1,s.length()-1);
			}
			cnt++;
			int base=1,sum=0;
			for (j=1;j<=10-cnt;j++) {
				sum+=base;
				base*=3;
			}
			for (j=1;j<=cnt-1;j++) {
				if (s[1]=='p') {
					s=s.substr(6,s.length()-1);
					sum+=2*base;
				} else if (s[1]=='i') {
					s=s.substr(7,s.length()-1);
					sum+=base;
				} else s=s.substr(6,s.length()-1);
				base*=3;
			}
				if (s[1]=='p') 
					sum+=2*base;
				else if (s[1]=='i') 
					sum+=base;
			a[i].c=sum;
			cin >> s;
		}
		sort(a+1,a+n+1,cmp);
		for (i=1;i<=n;i++) cout << a[i].name << endl;
		for (i=1;i<=30;i++) printf("=");
		printf("\n");
	}
	return 0;
}
