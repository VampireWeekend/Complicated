#include <cstdio>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int i,j;

float MyClock(int h,int m) {
	int i;
		if (h>=12) h-=12;
		int v=abs(h*60-m*11);
		if (v>360) v=720-v;
		if (v%2==0) return (float)(v/2); else return ((float)v)/2;
}

float YourClock(int HH,int MM) {
    int T,i,rad,rad1,rad2,rad3;
	  if (HH<12)   rad1=(HH*60+MM)-MM*12;
      if (HH==12)  rad1=MM-MM*12;
	  if (HH>12)   rad1=(HH-12)*60+MM-MM*12;
	  rad2=abs (rad1);
	  rad3=rad2%2;
      if(rad3==0)
	   {
          rad=rad2/2;
		  if (rad>180)
		  rad=360-rad;
	      return (float)rad;
	    }
	  else
	  { 
	      rad=rad2;
		  if(rad>360)
		  rad=720-rad;
	      return ((float)rad)/2;
	  }
}

int main () {
	for (i=0;i<=23;i++)
	    for (j=0;j<=59;j++) {
	    	float me=MyClock(i,j);
	    	float your=YourClock(i,j);
	    	if (me!=your) {
	    		cout << "Wrong Answer" << endl;
	    		cout << i << ":" << j << endl;
	    		cout << "My Answer:" << me << endl;
	    		cout << "Your Answer:" << your << endl;
	    	}
	    }
    return 0;	
}
