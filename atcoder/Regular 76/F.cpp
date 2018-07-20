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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
vector<int> v[maxn];

int main() {
	int n,m,i,j,l,r;
	scanf("%d%d",&n,&m);
	priority_queue<int,vector<int>,greater<int> > pq;
	for (i=1;i<=n;i++) {
		scanf("%d%d",&l,&r);
		if (l==0) pq.push(r); else v[l].push_back(r);
	}
	for (i=1;i<=m+1;i++) {
		sort(v[i].begin(),v[i].end());
	}
	int pos=-1;
	for (i=1;i<=m;i++) {     //枚举左界 
		if (v[i].size()>1) {     //当前左界有多个人，则只坐右界最大的那个人 
			for (j=0;j<v[i].size()-1;j++) pq.push(v[i][j]);
		} else if (v[i].size()==0) {   //当前左界无人
			if (!pq.empty()) {        //安排之前没坐的人坐到现在位置 
				if (pq.top()<=i) pq.pop(); else {
					pos=max(pos,i);
					while (!v[pos].size()&&pos<=m) pos++;
					if (v[pos].size()) v[pos].pop_back();
				}  
			} else {                  //安排后面的人坐到现在的位置 
				pos=max(pos,i);
				while (!v[pos].size()&&pos<=m) pos++;
				if (v[pos].size()) v[pos].pop_back();
			}
		}
	}
	int ans=pq.size();
	printf("%d\n",ans);
	return 0;
}
