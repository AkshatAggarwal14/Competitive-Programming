#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, ctr = 0;
    cin >> n;
    while (n)
    {
        int digit = n % 10;
        if (digit == 7 || digit == 4)
        {
            ctr++;
        }
        n /= 10;
    }
    if (ctr == 4 || ctr == 7)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}