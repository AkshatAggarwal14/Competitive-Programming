//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repeq(i, a, b) for (ll i = a; i <= b; i++)
#define repn(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    ll cnt0 = 0, cnt1 = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        char a = s[i];
        cnt0 += (a == '0');
        cnt1 += (a == '1');
    }
    ll ans = min(cnt0, cnt1);
    ll pref0 = 0, pref1 = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        char it = s[i];
        pref0 += (it == '0'), cnt0 -= (it == '0');
        pref1 += (it == '1'), cnt1 -= (it == '1');
        ans = min(min(ans, pref1 + cnt0), pref0 + cnt1);
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