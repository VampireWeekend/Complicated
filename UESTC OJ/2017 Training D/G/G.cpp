#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=111;
const ll mod=1e5;
int tree[maxn][4],fail[maxn],flag[maxn],num;
int id['Z'];
char a[15];

struct Matrix {
	ll a[111][111];
};

void insert (string s,int len) {
	int i,j,p=0;
	for (i=0;i<len;i++) {
		int pos=id[s[i]];
		if (!tree[p][pos]) {
			tree[p][pos]=++num;
		}
		p=tree[p][pos];
	}
	flag[p]=1;
}

void buildfail() {
	queue<int> q;
	int i;
	for (i=0;i<4;i++) {
		if (tree[0][i]) {
			q.push(tree[0][i]);
			fail[tree[0][i]]=0;
		}
	}
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (flag[fail[now]]) flag[now]=1;
		for (i=0;i<4;i++) {
			int to=tree[now][i];
			if (to) {
				fail[to]=tree[fail[now]][i];
				q.push(to);
			} else tree[now][i]=tree[fail[now]][i];
		}
	}
}

Matrix buildmap() {
	int i,j;
	Matrix map;
	for (i=0;i<=num;i++) 
		for (j=0;j<=num;j++) 
			map.a[i][j]=0;
	for (i=0;i<=num;i++) 
		for (j=0;j<4;j++)
	     	if (!flag[tree[i][j]]&&!flag[i]) 
	     		map.a[i][tree[i][j]]++;
/*	for (i=0;i<=num;i++) {
		for (j=0;j<=num;j++) {
			cout << map.a[i][j] << ' ';
		}
		cout << '\n';
	}*/
	return map;
}

Matrix operator*(const Matrix &x,const Matrix &y) {
	Matrix ans;
	int i,j,k;
	for (i=0;i<=num;i++) {
		for (j=0;j<=num;j++) {
			ans.a[i][j]=0;
			for (k=0;k<=num;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j];
				ans.a[i][j]%=mod;
			}
		}
	}
	return ans;
}

Matrix fastpower(Matrix s,ll index) {
	Matrix ans,base=s;
	ll k=index;
	int i,j;
	for (i=0;i<=num;i++) 
		for (j=0;j<=num;j++) 
			if (i==j) ans.a[i][j]=1; else ans.a[i][j]=0; 
	while (k) {
		if (k%2) ans=ans*base;
		base=base*base;
		k/=2;
	}
	return ans;
}

int main() {
	int n,i,j;
	ll m;
	scanf("%d%lld",&n,&m);
	id['A']=0;id['T']=1;id['C']=2;id['G']=3;
	num=0;
	memset(tree,0,sizeof(tree));
	memset(flag,0,sizeof(flag));
	memset(fail,0,sizeof(fail));
	for (i=1;i<=n;i++) {
		scanf("%s",a);
		insert(a,strlen(a));
	}
	buildfail();
	Matrix ans=fastpower(buildmap(),m);
	ll tot=0;
	for (i=0;i<=num;i++) {
		tot+=ans.a[0][i];
		tot%=mod;
	}
	printf("%lld\n",tot);
	return 0;
}
