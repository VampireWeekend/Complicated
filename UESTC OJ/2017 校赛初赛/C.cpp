#include <stdio.h>

int max(int a, int b)
{
  if(a > b)
	  return a;
  else 
	  return b;
}
int main()
{
	int x, y, ma, xg, yg, n;
	scanf("%d%d",&x, &y);
	if ((x%10==1)&&(y%10==9)&&(x>10)) {
		int a=max(x,y)/10-1+4;
		printf("%d",a);
		return 0;
	}
	if ((y%10==1)&&(x%10==9)&&(y>10)) {
		int a=max(x,y)/10-1+4;
		printf("%d",a);
		return 0;
	}
	ma = max(x,y);
	ma = ma / 10;
	xg = x % 10;
	yg = y % 10;
	switch(xg)
	{
	  case 0:
		  switch(yg)
		 { 
		 case 0: n = 0;break;
		 case 1: n = 1;break;  
		 case 2: n = 1;break; 
		 case 3: n = 2;break;
		 case 4: n = 2;break;
		 case 5: n = 1;break;
		 case 6: n = 2;break;
		 case 7: n = 2;break;
		 case 8: n = 3;break;
		 case 9: n = 3;break;
	     }
		 break;
	  case 1:
		 switch(yg)
		 { 
		 case 0: n = 1;break;
		 case 1: n = 1;break;  
		 case 2: n = 2;break;
		 case 3: n = 2;break;
		 case 4: n = 3;break;
		 case 5: n = 2;break;
		 case 6: n = 2;break;
		 case 7: n = 3;break;
		 case 8: n = 3;break;
		 case 9: n = 4;break;
	     }
		 break;
	  case 2:
		  switch(yg)
		  {
		  case 0: n = 1;break;
		  case 1: n = 2;break;  
		  case 2: n = 1;break;
		  case 3: n = 2;break;
		  case 4: n = 2;break;
		  case 5: n = 2;break;
		  case 6: n = 3;break;
		  case 7: n = 2;break;
		  case 8: n = 3;break;
		  case 9: n = 3;break;
		  }
		  break;
	  case 3:
		  switch(yg)
		  {
		  case 1: n = 2;break;  
		  case 2: n = 2;break;
		  case 0:
		  case 3: n = 2;break;
		  case 4: n = 3;break;
		  case 5: n = 3;break;
		  case 6: n = 3;break;
		  case 7: n = 3;break;
		  case 8: n = 3;break;
		  case 9: n = 4;break;
		  }
		  break;
	  case 4:
		  switch(yg)
		  {
		  case 1: n = 3;break;  
		  case 2: n = 2;break;
		  case 3: n = 3;break;
		  case 0:
		  case 4: n = 2;break;
		  case 5: n = 3;break;
		  case 6: n = 3;break;
		  case 7: n = 3;break;
		  case 8: n = 4;break;
		  case 9: n = 3;break;
		  }
		  break;
	  case 5:
		  switch(yg)
		  {
		  case 1: n = 2;break;  
		  case 2: n = 2;break;
		  case 3: n = 3;break;
		  case 4: n = 3;break;
		  case 0:
		  case 5: n = 1;break;
		  case 6: n = 2;break;
		  case 7: n = 2;break;
		  case 8: n = 3;break;
		  case 9: n = 3;break;
		  }
		  break;
	  case 6:
		  switch(yg)
		  {
		  case 1: n = 2;break;  
		  case 2: n = 3;break;
		  case 3: n = 3;break;
		  case 4: n = 3;break;
		  case 5: n = 2;break;
		  case 0:
		  case 6: n = 2;break;
		  case 7: n = 3;break;
		  case 8: n = 3;break;
		  case 9: n = 4;break;
		  }
		  break;
	  case 7:
		  switch(yg)
		  {
		  case 1: n = 3;break;  
		  case 2: n = 2;break;
		  case 3: n = 3;break;
		  case 4: n = 3;break;
		  case 5: n = 2;break;
		  case 6: n = 3;break;
		  case 0:
		  case 7: n = 2;break;
		  case 8: n = 3;break;
		  case 9: n = 3;break;
		  }
		  break;
	  case 8:
		  switch(yg)
		  {
		  case 1: n = 3;break;  
		  case 2: n = 3;break;
		  case 3: n = 3;break;
		  case 4: n = 4;break;
		  case 5: n = 3;break;
		  case 6: n = 3;break;
		  case 7: n = 3;break;
		  case 0:
		  case 8: n = 3;break;
		  case 9: n = 4;break;
		  }
		  break;
	  case 9:
		  switch(yg)
		  {
		  case 1: n = 4;break;  
		  case 2: n = 3;break;
		  case 3: n = 4;break;
		  case 4: n = 3;break;
		  case 5: n = 3;break;
		  case 6: n = 4;break;
		  case 7: n = 3;break;
		  case 8: n = 4;break;
		  case 0:
		  case 9: n = 3;break;
		  }
		  break;
	}

	n += ma;
	printf("%d",n);
	return 0;
}
