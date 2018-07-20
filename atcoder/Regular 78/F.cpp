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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,maxk=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

ll dis[maxn];
ll ma[maxn][maxn];

void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));       
	int now=s;
	memset(dis,-1,sizeof(dis));           
	dis[now]=0;
	vis[now]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)                     
			if(!vis[j]&&dis[now]+ma[now][j]>dis[j]&&ma[now][j]!=0) 
				dis[j]=dis[now]+ma[now][j] ;
		int mini=INF;
		for(int j=0;j<n;j++)                  
			if(!vis[j]&&dis[j]<mini) 
				mini=dis[cur=j];
		vis[cur]=true;
	}	
}

int main() {
	int n,m,i,x,y;
	num=0;
	scanf("%d%d",&n,&m);
	ll c,sum=0;
	mem0(ma);
	mem0(t);
	for (i=1;i<=m;i++) {
		scanf("%d%d%lld",&x,&y,&c);
		ma[x][y]=ma[y][x]=c;
		sum+=c;
	}
	sum=sum-spfa(1,n);
	printf("%lld\n",sum); 
	return 0;
}
