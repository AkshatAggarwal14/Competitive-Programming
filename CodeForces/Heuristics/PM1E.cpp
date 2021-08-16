#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int x, steps;
        cin >> x;
        if (x % 2 != 0)
        {
            steps = (x - 1) / 2 + 1;
        }
        else
        {
            steps = (x / 2);
        }
        cout << steps << endl;
    }
    return 0;
}