#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn=10005;
const int ti=6005;
vector<int> v[maxn];
int color[maxn],step[maxn];

int main() {
	int n,m,l,r=0,i,j,s,t,a,b;
	scanf("%d%d%d",&n,&m,&l);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	scanf("%d%d",&s,&t);
	if (s==t&&l==0) cout << "YES";
	for (j=1;j<=ti;j++) {
		r++;
		srand(r);
		for (i=1;i<=n;i++) {
			color[i]=rand()%(l-1)+1;
		}
		color[s]=0;color[t]=l;
		int mark[maxn]={0};
	//	memset(mark,0,sizeof(mark));
		int front=0,tail=1;
		step[1]=s;mark[s]=1;
		while (front<tail) {
			front++;
			int now=step[front];
			for (i=0;i<v[now].size();i++) {
				int to=v[now][i];
				if (color[to]==color[now]+1&&!mark[to]) {
					if (color[now]==l-1) {
						cout << "YES";
						return 0;
					}
					tail++;
					mark[to]=1;
					step[tail]=to;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}
