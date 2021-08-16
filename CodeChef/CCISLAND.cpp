//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
void solve()
{
    ll x, y, xr, yr, d;
    float fs, ws;
    cin >> x >> y >> xr >> yr >> d;
    fs = x / (float)xr;
    ws = y / (float)yr;
    float ans = min(fs, ws);
    if (d <= ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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