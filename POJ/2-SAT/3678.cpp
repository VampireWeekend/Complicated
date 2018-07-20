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
const int maxn=2005,maxk=2000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn];
int dfn[maxn],low[maxn],color[maxn];
bool inst[maxn];
int num=0,cnum=0;
stack<int> st;
char s[maxn];

struct Edge {
	int from,to,pre;
};
Edge edge[maxk];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
}

void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if (inst[to]) 
		    low[now]=min(low[now],dfn[to]); 
	}
	if (dfn[now]==low[now]) {
		inst[now]=0;
		color[now]=++cnum;
		while (st.top()!=now) {
			color[st.top()]=cnum;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}

int main() {
	int n,m,i,j,x,y,z;
	scanf("%d%d",&n,&m);
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<=m;i++) {
		scanf("%d%d%d%s",&x,&y,&z,s);
		x++;y++;
		if (s[0]=='O') {
			if (z==1) {
				addedge(x*2-1,y*2);
				addedge(y*2-1,x*2);
			} else {
				addedge(x*2,x*2-1);
				addedge(y*2,y*2-1);
				addedge(x*2-1,y*2-1);
				addedge(y*2-1,x*2-1);
			}
		}
		if (s[0]=='A') {
			if (z==0) {
				addedge(x*2,y*2-1);
				addedge(y*2,x*2-1);
			} else {
				addedge(x*2-1,x*2);
				addedge(y*2-1,y*2);
				addedge(x*2,y*2);
				addedge(y*2,x*2);
			}
		}
		if (s[0]=='X') {
			if (z==0) {
				addedge(x*2,y*2);
				addedge(x*2-1,y*2-1);
				addedge(y*2,x*2);
				addedge(y*2-1,x*2-1);
			} else {
				addedge(x*2,y*2-1);
				addedge(y*2,x*2-1);
				addedge(x*2-1,y*2);
				addedge(y*2-1,x*2);
			}
		}
	}
	num=0;
	mem0(dfn);mem0(low);mem0(color);mem0(inst);
	for (i=1;i<=2*n;i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (i=1;i<=n*2;i+=2) {
		if (color[i]==color[i+1]) {
			printf("NO\n");return 0;
		}
	}
	printf("YES\n");
	return 0;
}
