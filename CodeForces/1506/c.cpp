//*use cout<<"\n" instead of endl as endl is slower
// ! https://www.geeksforgeeks.org/longest-common-substring-dp-29/
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    string a, b;
    cin >> a >> b;
    ll n = a.length(), m = b.length();
    ll ans = n + m;
    for (ll j = 0; j <= min(n, m); j++)
    {
        for (ll x = 0; x <= n - j; x++)
        {
            for (ll y = 0; y <= m - j; y++)
            {
                if (a.substr(x, j) == b.substr(y, j))
                {
                    ans = n + m - j * 2;
                }
            }
        }
    }
    cout << ans << endl;
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