//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

ll ans = 0;

void solve()
{
    ll r, x;
    cin >> r >> x;
    ll canrun = 100 * x;
    ll torun = 22 * 2 * r / 7;
    if (torun <= canrun)
        ans++;
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
    cout << ans;
    return 0;
}