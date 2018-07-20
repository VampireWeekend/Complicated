#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
using namespace std;

int main()  {
	int c;
	srand((unsigned)time(NULL));
	printf("%d",rand()%9+1);
}
