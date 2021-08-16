/*There are three integers k,m,n. You have to convert the number k to m by performing the given operations:

Multiply k by n
Decrease k by 2.
Decrease k by 1*/
//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    ll k, m, n, ans = 0;
    cin >> k >> m >> n;
    while (k < m)
    {
        k *= n;
        ans++;
    }
    ans += (k - m) / 2 + (k - m) % 2;
    cout << ans << "\n";
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