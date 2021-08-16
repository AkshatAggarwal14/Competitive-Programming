//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countc(string s, char x)
{
    ll ctr = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == x)
        {
            ctr++;
        }
    }
    return ctr;
}

void solve()
{
    ll N, M;
    cin >> N >> M;
    ll X, Y;
    cin >> X >> Y;
    string ans[N];
    for (ll i = 0; i < N; i++)
        cin >> ans[i];
    for (ll i = 0; i < N; i++)
    {
        ll f, p;
        f = countc(ans[i], 'F');
        p = countc(ans[i], 'P');
        // cout << f << " " << p << " Hello\n";
        if ((f >= X) || ((f == X - 1) && (p >= Y)))
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
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