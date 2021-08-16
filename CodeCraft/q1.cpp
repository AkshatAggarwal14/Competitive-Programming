#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    ll p = gcd(b, a % b);
    return p;
}

ll gcdSum(ll n)
{
    ll t = n;
    ll digsum = 0;
    while (n)
    {
        digsum += n % 10;
        n /= 10;
    }
    return gcd(t, digsum);
}

void solve()
{
    ll x;
    cin >> x;
    do
    {
        if (gcdSum(x) > 1)
        {
            cout << x << endl;
            break;
        }
    } while (x++);
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}