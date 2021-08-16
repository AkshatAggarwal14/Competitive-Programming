//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    ll n, ans;
    cin >> n;
    if (n % 12 == 0)
        ans = n - 11;
    else
        ans = 12 * (n / 12 + 1) - n + 1 + 12 * (n / 12);
    ll diff = abs(n - ans);
    string seat;
    if (diff == 1 || diff == 11)
        seat = " WS\n";
    else if (diff == 3 || diff == 9)
        seat = " MS\n";
    else if (diff == 5 || diff == 7)
        seat = " AS\n";
    cout << ans << seat;
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