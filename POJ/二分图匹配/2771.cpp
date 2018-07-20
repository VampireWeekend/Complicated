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
//����ͼ��Ȩ��������������Ȩ����ͼG�е�һ���Ӽ�V������һ���ߵ������˵㲻��ͬʱ����V����V�е�Ȩ�����
//�㸲�Ǽ��Ĳ������Ƕ���������Ϊ�㸲�Ǽ���ÿ���߶����ٱ�һ���㸲�ǣ������Ͳ����ܴ���һ���ߵ������˵㡣
//��ô��Ȼ������ͼ��Ȩ��������=����ͼ��Ȩ��-����ͼ��С��Ȩ���Ǽ�
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
