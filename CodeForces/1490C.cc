#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll num, flag = 0, left, cbrtLeft;
    cin >> num;
    for (ll i = 1; i < cbrt(num); i++)
    {
        left = num - (i * i * i);
        cbrtLeft = cbrt(left);
        if (left == cbrtLeft * cbrtLeft * cbrtLeft)
        {
            cout << "YES\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "NO\n";
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}