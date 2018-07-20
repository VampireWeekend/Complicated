#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	int n,i,j,flag;
    scanf("%d",&n);
    while (n!=0) {
    	flag=0;
    	if (n<=20) {
    		if (n<=2) printf("No such base\n");
    		if (n==3) printf("4\n");
    		if (n==4||n==5||n==6) printf("No such base\n");
    		if (n>6) {
    			n-=3;
    			for (i=4;i<=n;i++) {
    	    		if (n%i==0) {
    		    		printf("%d\n",i);
    		    		break;
    		    	}
    	    	}
    		}
    	} else {
    		n-=3;
    		for (i=4;i<=sqrt(n);i++) {
    			if (n%i==0) {
    				printf("%d\n",i);
    				flag=1;
    				break;
    			}
    		}
    		if (!flag) {
    			if (n%3==0) {
    		    	printf("%d\n",n/3);
    	     	} else 
    	    	if (n%2==0) printf("%d\n",n/2); else printf("%d\n",n);
    		}
    	}
    	scanf("%d",&n);
    }
    return 0;
}
