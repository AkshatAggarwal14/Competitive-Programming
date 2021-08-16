//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll t = 0, m;
    for (ll j = 0; j < str.length(); j++)
        if (str[j] == 'T')
            t++;
    m = str.length() - t;
    if (str.length() % 3 == 0 && t == 2 * m && (str.find("TMT") > 0 || str.find("TM") > 0 || str.find("MT") > 0) && str[0] == 'T')
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