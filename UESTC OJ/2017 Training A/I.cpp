#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	int a,b,n,x,ans,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		q.push(x);
	}
	ans=0;
	for (i=1;i<=n-1;i++) {
		ans+=a=q.top();
		q.pop();
		ans+=b=q.top();
		q.pop();
		q.push(a+b);
	}
	printf("%d",ans);
	return 0;
}
