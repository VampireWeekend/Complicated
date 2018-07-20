#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int a;

int main() {
	int n,i;
	scanf("%d",&n);
	set<int> s;
	set<int>::iterator iter;
	s.clear();
	for (i=1;i<=n;i++) {
		scanf("%d",&a);
		s.insert(a);
	}
	int k,min,now;
	while (1) {
		min=k=now=*(--s.end());
		while (k>1) {
			k/=2;
			if ((iter=s.find(k))==s.end()) min=k;
		}
		if (min==now) break;
		s.erase(now);
		s.insert(min);
	}
	printf("%d",now);
	return 0;
} 
/*
8
78 56 42 14 98 74 4 3
14 9 7 5 4 3 2 1
*/
