#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main () 
{
	float x,y,t,s;
	float ans;
	int n,i,k;
	cin >> n;
	for (k=1;k<=n;k++) 
	{
		cin >> x >> y >> t >> s;
		ans=0;
		if (x>y) 
		{
			float down,time;
			down = t*y;
			while (down+y*(down/(x-y))<s) 
			{
				time = down/(x-y) ;
				ans+=time;
				down+=y*time;
			}
			ans+=s/x;
		}
	    if (x<=y) ans=s/x;
		cout << setiosflags(ios::fixed) << setprecision(3);
		cout << "Case #" << k << ": " << ans << endl;
	}
	return 0;
}
