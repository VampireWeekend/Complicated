#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	int n,i,j,flag,k;
 //   scanf("%d",&n);
 //   while (n!=0) {
    for (k=10;k<=18;k++) {
    	flag=0;
    	int ans,ans2,n;
    	n=k;
    	if (n<=9) {
    		if (n<=6) {
    	    	if (n==3) printf("4\n"); else printf("No such base\n");
    		}else {
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
    		int x=sqrt(n);
    		for (i=4;i<=x;i++) {
    			if (n%i==0) {
    			//	printf("%d\n",i);
    			    ans=i;
    				flag=1;
    				break;
    			}
    		}
    		if (!flag) {
    			if (n%3==0) {
    		  //  	printf("%d\n",n/3);
    		        ans=n/3;
    	     	} else 
    	    	if (n%2==0) 
				//printf("%d\n",n/2); else printf("%d\n",n);
				ans=n/2; else ans=n;
    		}
    	}
    	for (i=4;i<=k-3;i++) {
    			if ((k-3)%i==0) {
    			//	printf("%d\n",i);
    			    ans2=i;
    				break;
    			}
    		}
    	if (ans!=ans2) cout << k << ' ' << ans << ' ' << ans2 << endl;
  //  	scanf("%d",&n);
    }
    return 0;
}
