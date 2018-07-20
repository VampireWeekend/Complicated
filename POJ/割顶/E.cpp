#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=50005;
struct submission {
	char name[30],problem[5];
	int time,result;
};
submission a[maxn];

struct problem {
	int tot,fail;
};

struct team {
	char name[30];
	problem p[30];
};

bool cmp(submission x,submission y) {
	return 
	(x.name<y.name) || (x.name==y.name&&x.problem<y.problem)
}

int main() {
	int c,t;
	scanf("%d",&c);
	map<string,int> my;
	my["YES"]=3;my["NO"]=2;my["ERROR"]=1;
	for (t=1;t<=c;t++) {
		int n,m,tot,fro;
		printf("Case #%d:\n",t);
		scanf("%d%d%d%d",&n,&m,&tot,&fro);
		char q[25];
		for (i=1;i<=n;i++) {
			scanf("%s%s%d%s",a[i].name,a[i].problem,&a[i].time,q);
			a[i].result=my[q];
		}
		sort(a+1,a+n+1,cmp);
	}
	return 0;
}
