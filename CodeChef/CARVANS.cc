//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int k = a[0], ans = 1;
    rep(i, 1, n)
    {
        if (a[i] <= k)
        {
            k = a[i];
            ans++;
        }
    }
    cout << ans << '\n';
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