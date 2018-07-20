#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ld p[maxn],survive[maxn],happy[maxn],dieval[maxn];
ll v[maxn],sum[maxn];
char s[155];

int main() {
	int n,w,i,j,last;
	scanf("%d%d",&n,&w);
	last=0;
	survive[0]=1;
	sum[0]=0;
	ld val=0L;
	double k;
	v[0]=0;
	dieval[0]=0L;
	for (i=1;i<=n;i++) {
		scanf("%s%lf%d",s,&k,&v[i]);
		p[i]=(ld)k;
		survive[i]=p[i]*survive[i-1];
		ld die=survive[i-1]-survive[i];
	//	if (i!=1) sum[i]=sum[i-1]+v[i]; else sum[i]=w+v[i];
		happy[i]=survive[i]*log((ld)(1L+(ld)(v[i])/(ld)(w))); //(???)sum[i]///w
		if (last!=0) {
			dieval[i]=dieval[i-1]+die*log((ld)(1L+(ld)(v[last])/(ld)(w)));
			happy[i]+=dieval[i];
		}
		val=max(val,happy[i]);
		if (s[0]=='s') 
			last=i;
	}
	cout << setiosflags(ios::fixed) << setprecision(2);
	ld l,r,mid;
	l=0.0L,r=1000000.0L;
	while (abs(l-r)>0.00001L) {
		mid=(l+r)/2.0L;
		if (log(1.0L+(mid/(ld)(w)))>val) r=mid; else l=mid;
	}
	cout << "$";
	cout << mid << endl; 
	return 0;
}
