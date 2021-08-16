#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x, n, p;
    cin >> x >> n;
    if (n % 2 != 0)
        p = (n - 1) * (n - 1) / 4;
    else
        p = n * (n - 2) / 4;
    cout << p << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}