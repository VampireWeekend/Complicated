#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;
const int maxn=10005;
int a[maxn],color[maxn],dfn[maxn],low[maxn],instack[maxn],b[maxn];
vector<int> v[maxn];
int num,cnum;
stack<int> s;

void tarjan (int now) {
	dfn[now]=low[now]=++num;
	s.push(now);
	int i;
	instack[now]=1;
	for (i=0;i<v[now].size();i++) {
		int to=v[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if (instack[to]) 
		    low[now]=min(low[now],dfn[to]); 
	}
	if (dfn[now]==low[now]) {
		instack[now]=0;
		color[now]=++cnum;
		while (s.top()!=now) {
			color[s.top()]=cnum;
			instack[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}

int main() {
	int n,i,j,k;
	scanf("%d%d",&n,&k);
	memset(color,0,sizeof(color));
	memset(instack,0,sizeof(instack));
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		v[i].push_back(a[i]);
		b[a[i]]=i;
	}
	num=0,cnum=0;
	for (i=1;i<=n;i++) {
		if (!color[i]) tarjan(i);
	}
	for (i=1;i<=n;i++) {
		if (color[i]!=color[a[i]]) {
			cout << "Impossible";
			return 0;
		}
	}
	for (i=1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}
