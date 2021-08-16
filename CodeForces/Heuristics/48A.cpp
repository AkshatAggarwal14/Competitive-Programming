#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x;
    cin >> x;
    if (x == (int)x)
        cout << ceil(x / 5);
    else
        cout << (int)x / 5 + 1;
    return 0;
}
