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
const int maxn=2505,maxk=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],dist[maxn];
int path[maxn],rflow[maxn];
int sc[maxn],sf[maxn];
bool inque[maxn];
int num,cnt,sumc,sumf,sum;

struct Edge {  
    int from,to,cost,flow,pre;  
};  
Edge edge[maxk*2];  
  
void addedge(int s,int t,int cost,int flow) {  
    edge[num]=(Edge){s,t,cost,flow,head[s]};  
    head[s]=num++;  
    edge[num]=(Edge){t,s,-cost,0,head[t]};  
    head[t]=num++;  
}  
  
int spfa(int s,int t) {  
    mem0(inque);meminf(dist);  
    memset(path,-1,sizeof(path));  
    memset(rflow,-1,sizeof(rflow));  
    queue<int> q;  
    q.push(s);  
    inque[s]=1;  
    int i;  
    dist[s]=0;  
    rflow[s]=inf;  
    while (!q.empty()) {  
        int now=q.front();  
        q.pop();  
        inque[now]=0;  
        for (i=head[now];i!=-1;i=edge[i].pre) {  
            int to=edge[i].to;  
            if (edge[i].flow>0&&dist[now]+edge[i].cost<dist[to]) {  
                dist[to]=dist[now]+edge[i].cost;  
                path[to]=i;  
                rflow[to]=min(rflow[now],edge[i].flow);  
                if (!inque[to]) {  
                    inque[to]=1;  
                    q.push(to);  
                }  
            }  
        }  
    }  
    if (dist[t]==inf) return 0; else return dist[t];  
}  
  
int MCMF(int s,int t,int k) {  
    int f,now;  
    sum=0;
    while (f=spfa(s,t)) {  
        now=path[t];  
        while (now!=-1) {  
            edge[now].flow-=rflow[t];  
            edge[now^1].flow+=rflow[t];  
            now=path[edge[now].from];  
        }
        cnt++;
        sc[cnt]=f;
        sf[cnt]=rflow[t];sum+=rflow[t];
    }  
}  

int main() {
	int n,m,k;
	while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
		int i,j,x,y,z;
		num=cnt=0;memset(head,-1,sizeof(head));
		for (i=1;i<=m;i++) {
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,1,z);
		}
		if (k==0) {
			printf("0\n");
			continue;
		}
		n--;
		int ans=0;
		MCMF(0,n,k);
		if (sum==0) {
			printf("No solution\n");continue;
		}
		sumc=sumf=0;
		for (i=1;i<=cnt;i++) {
			int pre=sumf;
			sumf+=pre*(sc[i]-sumc-1);
			if (sumf>=k) {
				ans=sumc+(k-pre)/pre+((k-pre)%pre!=0);
				break;
			}
			sumf+=sf[i]+pre;
			ans=sumc=max(sc[i],sumc);
			if (sumf>=k)
				break;
		}
		if (sumf<k)
			ans=sumc+(k-sumf)/sum+((k-sumf)%sum!=0);
		printf("%d\n",ans);
	}
	return 0;
}
