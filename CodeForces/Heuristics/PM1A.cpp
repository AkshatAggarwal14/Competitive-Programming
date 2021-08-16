#include <iostream>
using namespace std;

int main()
{
    long int x, steps;
    cin >> x;
    if (x % 5 != 0)
    {
        steps = (x / 5) + 1;
    }
    else
    {
        steps = (x / 5);
    }
    cout << steps;
    return 0;
}