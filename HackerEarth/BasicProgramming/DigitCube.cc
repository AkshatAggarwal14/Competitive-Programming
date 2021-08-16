//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

ll digitCube(ll n, ll k)
{
    ll s = 0, ans;
    while (n)
    {
        int dig = n % 10;
        s += dig;
        n /= 10;
    }
    if (k == 1)
        return s * s * s;
    if (k != 1)
        digitCube(s * s * s, k - 1);
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    n = digitCube(n, k);
    cout << n << "\n";
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