#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <math.h>
using namespace std;
const int maxn=100005;

int main() {
	int n,i,j,flag;
    for (j=(1<<30)-1;j<=(1<<30)-1;j++) {
    	flag=0;
    	n=(1<<31)-1;
    		if (n<=2) printf("No such base\n");
    		if (n==3) printf("4\n");
    		if (n==4||n==5||n==6) printf("No such base\n");
    		if (n>6) {
    			n-=3;
    			for (i=4;i<=n;i++) {
    			if (n%i==0) {
    				printf("%d\n",i);
    				flag=1;
    				break;
    			}
    	    	}
    	    	continue;
    		}
    	
    }
    return 0;
}
