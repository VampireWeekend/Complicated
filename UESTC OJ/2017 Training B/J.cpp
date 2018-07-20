#include <cstdio>
#include <queue>
#include <deque>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int maxn=505,maxk=1005;
const int inf=0x3f3f3f3f;
int dist[maxn],num,n,m;
int head[maxn],t[maxn];
bool inque[maxn];
vector<int> v[maxn];
vector<int> d[maxn];

bool spfa(int s,int n) {
	deque<int> q;
	memset(inque,0,sizeof(inque));
	memset(t,0,sizeof(t));
	q.push_back(s);
	dist[s]=0;
	inque[s]=1;
	t[s]=1;
	int i;
	while (!q.empty()) {
		int now=q.front();
		q.pop_front();
		inque[now]=0;
		for (i=0;i<v[now].size();i++) {
			int to=v[now][i];
			if (dist[now]+d[now][i]<dist[to]) {
				dist[to]=dist[now]+d[now][i];
				if (!inque[to]) {
					if (!q.empty()) {
						if (dist[to]<dist[q.front()])  //small label first
					        q.push_front(to);
					    else q.push_back(to);
					} else q.push_back(to);
					t[to]++;
					if (t[to]>n) return false;
					inque[to]=1;
				}
			}
		}
	}
	return true;
}

int main() {
	int n,p,q,s,t,i,j;
	scanf("%d%d%d%d%d",&n,&p,&q,&s,&t);
	memset(dist,0x3f,sizeof(dist));
	 //sum[p+i]-sum[i]>=s
	for (i=0;p+i<=n;i++) {
		v[i+p].push_back(i);
		d[i+p].push_back(-s);
	} 
	//sum[i]-sum[q+i]>=-t
	for (i=0;q+i<=n;i++) {
		v[i].push_back(q+i);
		d[i].push_back(t);
	}
	int flag=1;
	flag=flag&spfa(0,n);
	for (i=1;i<=n;i++) {
		if (dist[i]==inf) flag=flag&spfa(i,n);
	}
	if (flag) {
		cout << "Yes" << endl;
		for (i=1;i<=n;i++) {
			printf("%d ",dist[i]-dist[i-1]);
		}
	} else cout << "No";
	return 0;
}
