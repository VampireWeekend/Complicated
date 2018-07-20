#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <vector> 
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;
const int maxn=504;
int match[maxn],visit[maxn],sex[maxn],h[maxn],pre[maxn];
vector<int> v[maxn];
queue<int> q;
int i,j,ans,n;
string s,music[maxn],sport[maxn];
//二分图点权最大独立集：带点权二分图G中的一个子集V，其中一条边的两个端点不能同时属于V，且V中点权和最大。
//点覆盖集的补集就是独立集，因为点覆盖集中每个边都至少被一个点覆盖，补集就不可能存在一条边的两个端点。
//那么显然：二分图点权最大独立集=二分图点权和-二分图最小点权覆盖集
bool dfs(int now) {
	int size=v[now].end()-v[now].begin();
	int i,to;
	for (i=0;i<size;i++) {
		to=v[now][i];
		if (!visit[to]) {
			visit[to]=true;
			if (!match[to]||dfs(match[to])) {
				match[to]=now;
				match[now]=to;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int t,q;
	cin >> q;
	stringstream stream;
	for (t=1;t<=q;t++) {
		ans=0;
	    cin >> n;
	    for (i=1;i<=n;i++) {
	    	cin >> s;
		    stream << s;
	    	stream >> h[i];
	    	stream.clear();
	    	cin >> s;
	    	if (s[0]=='M') sex[i]=1; else sex[i]=2;
	    	cin >> music[i];
	    	cin >> sport[i];
	    	for (j=1;j<=i-1;j++) 
	    		if ((sex[i]!=sex[j])&&(music[i]==music[j])&&(abs(h[i]-h[j])<=40)&&(sport[i]!=sport[j])) {
	    			v[i].push_back(j);
	    			v[j].push_back(i);
	    		}
	    }
	    memset(match,0,sizeof(match));
	    for (i=1;i<=n;i++) 
		    if (!match[i]) {
		    	memset(visit,0,sizeof(visit));
	    	    ans+=dfs(i);
	        }
		cout << n-ans << endl;
		for (i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}
