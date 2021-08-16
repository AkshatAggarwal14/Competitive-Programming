//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repeq(i, a, b) for (ll i = a; i <= b; i++)
#define repn(i, n) for (ll i = 0; i < n; i++)

ll findTrailingZeros(ll n)
{
    ll count = 0;
    for (ll i = 5; n / i >= 1; i *= 5)
        count += n / i;
    return count;
}

void solve()
{
    ll x, n;
    cin >> x >> n;
    cout << findTrailingZeros(n) << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}