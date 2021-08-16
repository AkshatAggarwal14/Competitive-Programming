#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll D(ll n, ll k)
{
    if (k == 1 && n == 1)
        return 1;
    else if (n == 1 && k != 1)
        return 2;
    else if (k == 1 && n != 1)
        return 1;
    else
    {
        ll sum = 1 + (k * (n - 1)) % (1000000007);
        for (ll i = k - 1, j = n - 2; j >= 1 && i >= 1; i--, j -= 2)
        {
            sum += D(j, i) % (1000000007);
        }
        return sum;
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    cout << D(n, k) << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}