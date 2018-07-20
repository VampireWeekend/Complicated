#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int maxl=205;
int mark[27],d[27];
char s[27],c[27];
char a[maxl],b[maxl];
vector<int> v[27];

int main() {
	int n,i,j;
	scanf("%d",&n);
	scanf("%s",a);
	memset(d,0,sizeof(d));
	memset(mark,0,sizeof(mark));
	for (i=2;i<=n;i++) {
		scanf("%s",b);
		int lena=strlen(a),lenb=strlen(b),k=0;
		while (k<lena&&k<lenb&&a[k]==b[k])
		    k++;
		if (k>=lena||k>=lenb) {
			if (lena>lenb) {
				cout << -1;
				return 0;
			}
		} else {
		    d[b[k]-'a']++;
		    v[a[k]-'a'].push_back(b[k]-'a');
		}
        for (j=0;j<lenb;j++) a[j]=b[j];
        a[lenb]='\0';
	}
	i=0;
	queue<int> q;
	while (i<26) {
		int flag=0;
		for (j=0;j<26;j++) {
			if (!mark[j]&&d[j]==0) {
				s[i]=(char)('a'+j);
				i++;
				mark[j]=1;
				q.push(j);
				flag=1;
				if (v[j].size()!=0) break;
			}
		}
		if (!flag) {
			cout << -1;
			return 0;
		}
		while (!q.empty()) {
			int now=q.front();
			q.pop();
			for (j=0;j<v[now].size();j++) d[v[now][j]]--;
		}
	}
	s[26]='\0';
	printf("%s",s);
	return 0;
}
