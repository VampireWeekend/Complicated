#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=500005,maxk=5000005,inf=0x3f3f3f3f;
int num=0,current[maxn],head[maxn],r[maxn],dirx[4],diry[4];
char map[28][28];
struct Edge{
	int to,flow,pre;
} edge[maxk];

void addedge(int from,int to,int flow) {
	edge[num]=(Edge){to,flow,head[from]};
	head[from]=num++;
	edge[num]=(Edge){from,0,head[to]};
	head[to]=num++;
}

bool bfs(int n) {
	queue<int> q;
	memset(r,-1,sizeof(r));
	q.push(0);
	r[0]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (r[to]==-1&&edge[i].flow>0) {
				r[to]=r[now]+1;
				q.push(to);
			}
		}
	}
	return r[n]!=-1;
}

int dfs(int now,int flow,int des) {
	if (now==des) return flow;
	int f;
	for (int i=current[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		current[now]=i;
		if (edge[i].flow>0&&r[to]==r[now]+1) {
			if (f=dfs(to,min(flow,edge[i].flow),des)) {
				edge[i].flow-=f;
				edge[i^1].flow+=f;
				return f;
			}
		}
	}
	return 0;
}

int dinic(int n) {
	int i,f,sum=0;
	while (bfs(n)) {
		memcpy(current,head,sizeof(head));
		while (f=dfs(0,inf,n)) sum+=f;
	}
//	cout << n << ' ' << sum << endl; 
	return sum;
}

void buildgraph(int mid,int n) {
	num=0;
	memset(head,-1,sizeof(head));
	int i,k=0,l,j,m;
	for (i=1;i<=n;i++) {
		addedge(0,(i-1)*mid*n+1,1);
		addedge(i*n*mid,n*n*mid+1,1);
		for (j=1;j<=n;j++) {
			k++;
		    for (l=1;l<mid;l++) {
		    	addedge((k-1)*mid+l,(k-1)*mid+l+1,1);
		    	if (map[i][j-1]=='.')
		    	for (m=0;m<4;m++) {
		    		int nowx=i+dirx[m],nowy=j+diry[m];
		    		if (map[nowx][nowy-1]=='.'&&nowx>0&&nowx<=n&&nowy>0&&nowy<=n) {
		    			int u=(nowx-1)*n+nowy;
		    			addedge((k-1)*mid+l,(u-1)*mid+l+1,1);
		    		}
		    	}
		    }
		}
	}
}

int solve(int n) {
	int l=1,r=n*n+5,mid,ans=-1;
	while (l<=r) {
		mid=(l+r)/2;
		buildgraph(mid,n);
		if (dinic(mid*n*n+1)>=n) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	return ans-1;
}

int main() {
	int n,t=0,i;
	scanf("%d",&n);
	dirx[0]=dirx[1]=diry[2]=diry[3]=0;
	dirx[2]=1;dirx[3]=-1;
	diry[0]=1;diry[1]=-1;
	while (n) {
		t++;
		for (i=1;i<=n;i++) {
			scanf("%s",map[i]);
		}
		int ans=solve(n);
		printf("Case %d: %d\n",t,ans);
		scanf("%d",&n);
	}
	return 0;
}
