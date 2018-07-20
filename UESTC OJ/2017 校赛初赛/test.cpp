#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long i;
    cin >> i;
    long long j=i/3;
    if (i%3==0) cout << j; else cout << j+1;
    return 0;
}

