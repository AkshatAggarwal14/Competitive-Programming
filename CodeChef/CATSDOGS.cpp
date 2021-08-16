#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, c, d, legs, add;
    cin >> t;
    while (t--)
    {
        cin >> c >> d >> legs;
        add = max(c - 2 * d, 0ll);
        if (legs % 4 == 0 && legs >= 4 * (d + add) && legs <= (c + d) * 4)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}