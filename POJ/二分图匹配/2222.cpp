#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=15,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char mp[maxn][maxn];
bool e[25][25];
int hash[25][2],head[25],match[25];
char s[maxn];
bool visit[25];
int ans,num;

struct Edge {
	int from,to,pre;
};
Edge edge[505];

void addedge(int from,int to) {
	if (e[from][to]||e[to][from]) return;
	e[from][to]=e[to][from]=1;
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

bool hungary(int now) {
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			visit[to]=1;
			if (!match[to]||hungary(match[to])) {
		    	match[to]=now;
		    	match[now]=to;
		     	return true;
		    }
		}
	}
	return false;
}

int main() {
	while (scanf("%s",s)!=EOF) {
		int n,m,i,j,k=0;
		scanf("%d%d",&n,&m);
		char c;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				scanf("%c",&c);
				while (!(c>='A'&&c<='Z')) scanf("%c",&c);
				mp[i][j]=c;
				if (c!='E') {
					hash[++k][0]=i;hash[k][1]=j;
				}
			}
		}
		memset(head,-1,sizeof(head));
		num=0;
		mem0(e);
		for (i=1;i<=k;i++) {
			if (mp[hash[i][0]][hash[i][1]]=='K') {
				for (j=1;j<=k;j++) {
					if (i!=j&&abs(hash[i][0]-hash[j][0])<=1&&
					abs(hash[i][1]-hash[j][1])<=1) addedge(i,j);
				}
			}
			if (mp[hash[i][0]][hash[i][1]]=='Q') {
				for (j=1;j<=k;j++) {
					if (i!=j)
					if (hash[i][0]==hash[j][0]||hash[i][1]==hash[j][1]||
					abs(hash[i][0]-hash[j][0])==abs(hash[i][1]-hash[j][1])) 
						addedge(i,j);
				}
			}
			if (mp[hash[i][0]][hash[i][1]]=='B') {
				for (j=1;j<=k;j++) {
					if (i!=j)
					if (abs(hash[i][0]-hash[j][0])==abs(hash[i][1]-hash[j][1])) 
						addedge(i,j);
				}
			}
			if (mp[hash[i][0]][hash[i][1]]=='R') {
				for (j=1;j<=k;j++) {
					if (i!=j)
					if (hash[i][0]==hash[j][0]||hash[i][1]==hash[j][1]) 
						addedge(i,j);
				}
			}
			if (mp[hash[i][0]][hash[i][1]]=='N') {
				for (j=1;j<=k;j++) {
					if (i!=j)
					if ((abs(hash[i][0]-hash[j][0])==1&&abs(hash[i][1]-hash[j][1])==2)
					||(abs(hash[i][0]-hash[j][0])==2&&abs(hash[i][1]-hash[j][1])==1)) 
						addedge(i,j);
				}
			}
		}
		ans=0;
		mem0(match);
		for (i=1;i<=k;i++) {
			if (!match[i]) {
				mem0(visit);
				if (hungary(i)) ans++; 
			}
		}
		printf("Minimum Number of Pieces to be removed: %d\n",ans);
		scanf("%s",s);
	}
	return 0;
}

