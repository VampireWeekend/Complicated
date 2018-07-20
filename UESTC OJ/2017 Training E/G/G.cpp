#include <cstdio>
#include <iostream>
#include <stdio.h>
using namespace std;
const long long mod=1e9+7;
long long p[200001];
long long a[200001],b[200002];
int n,i,j;
long long ans=0; 
char ch[200001];

long long fastpow(long long base,long long index) {
	long long sum=base,an=1;
	long long i=index;
    while (i) {
    	if (i%2) an=(an*sum)%mod;
    	sum*=sum;
    	sum=sum%mod;
    	i/=2;
    }
    return an;
}

long long lucas(long long n,long long m){
	if (n<m) {
		return 0;
	} else return p[n]*(fastpow((p[m]*p[n-m])%mod,mod-2)%mod)%mod;
}

int main () {
	n=0;
	a[0]=0;
	p[0]=1; 
	while (scanf("%c",&ch[++n])!=EOF) {
	    if (ch[n]=='0') a[n]=a[n-1]+1; else a[n]=a[n-1];
	    p[n]=(p[n-1]*n)%mod;
	}
	b[n+1]=0;
	for (i=n;i>=1;i--) {
		if (ch[i]=='1') b[i]=b[i+1]+1; else b[i]=b[i+1];
	}
	for (i=1;i<=n;i++) {
		if (ch[i]=='0') {
			ans+=lucas(a[i]+b[i]-1,b[i]-1);
			ans%=mod;
		}		
	}
	cout << ans << endl;
	return 0;
}
