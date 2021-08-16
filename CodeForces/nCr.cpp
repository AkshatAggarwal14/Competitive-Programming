#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C(ll n, ll r)
{
    ll ncr;
    ncr = fact(n) / (fact(r) * fact(n - r));
    return ncr;
}

ll fact(ll n)
{
    ll i, f = 1;
    for (i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

void solve()
{
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