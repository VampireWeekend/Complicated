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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
	int a,b,c;
	while (scanf("%d%d",&a,&b)!=EOF) {
		if (a>b) {
			c=a;a=b;b=c;
		}
		if (floor((b-a)*(sqrt(5.0)+1.0)/2.0)==a) printf("0\n"); 
		    else printf("1\n"); 
	}
	return 0;
}

