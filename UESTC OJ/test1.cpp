#include <stdio.h>
#include <stdlib.h>
#include <cmath>
int main ()
{
	int T,i,HH,MM,rad,rad1,rad2;
	scanf("%d",&T);
	scanf("%d:%d",&HH,&MM);
	for(i=T;i>0;i--)
	{
    	if (HH<12) rad1=(HH*60+MM)-MM*12;
        if (HH==12) rad1=MM-MM*12;
    	if (HH>12) rad1=(HH-12)*60+MM-MM*12;
	    rad2=abs (rad1);
	    if (rad2>360) rad2=720-rad2;
	    if(rad2%2==0)
    	{
           rad=rad2/2;
       	   printf("%d",rad);
    	}
     	else
    	{ 
    	   rad=rad2;
    	   printf("%d",rad);
    	   printf("/2");
    	}
    }
    return 0;
}
