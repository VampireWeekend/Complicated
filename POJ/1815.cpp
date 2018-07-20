//����ͼ��С����ȷ�����S���յ�T��ÿ���㶼���Լ��ĵ�Ȩֵvi��
//����С��Ȩ�͵ĸ�㼯��ʹ��S�޷�����T��
//�ⷨ����ÿ������Ϊ������v��v'��֮���ȨֵΪvi��
//��ԭͼ�е�ÿ���߸�ȨֵΪINF������󣩣�Ȼ��ʹ��������㷨��
//���S��T�������������Ӧ����С����и�߼����ӵĵ��γɵĵ㼯������С����
#include <cstdio>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int maxn=405,maxk=12005,inf=0x3f3f3f3f;
int num;
struct Edge{
	int from,to,flow,pre;
};
Edge edge[maxk];
int head[maxn],current[maxn],dist[maxn];

void addedge(int s,int t,int f) {
	Edge e;
	e.from=s;e.to=t;e.flow=f;e.pre=head[s];
	edge[num]=e;head[s]=num++;
	e.from=t;e.to=s;e.flow=0;e.pre=head[t];
	edge[num]=e;head[t]=num++;
}

bool bfs(int s,int t) {
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	queue<int> q;
	q.push(s);
	int i;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[to]==0) {
				q.push(to);
				dist[to]=dist[now]+1;
			}
		}
	}
	return dist[t]!=-1;
}

int dfs(int now,int t,int flow) {
	int i,f;
	if (now==t) return flow;
	for (i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (dist[to]==dist[now]+1&&edge[i].flow>0&&(f=dfs(to,t,min(flow,edge[i].flow)))) {
			edge[i].flow-=f;
			edge[i^1].flow+=f;
		}
	}
}

int dinic(int s,int t) {
	int f,sum=0;
	while (bfs(s,t)) {
		memset(current,-1,sizeof(current));
		while (f=dfs(s,t,inf))
		    sum+=f;
	}
	return sum;
}

int main() {
	int n,s,t,i,j,x;
	scanf("%d%d%d",&n,&s,&t);
	memset(head,-1,sizeof(head));
	num=0;
	for (i=1;i<=n;i++) {
		addedge(0,i,inf);
		addedge(i,i+n,1);
		addedge(i+n,2*n+1,inf);
		for (j=1;j<=n;j++) {
			scanf("%d",&x);
			if (x==1) {
				addedge(i,j+n,inf);
			}
		}
	}
	int ans=dinic(0,2*n+1);
	cout << ans;
	return 0;
}
