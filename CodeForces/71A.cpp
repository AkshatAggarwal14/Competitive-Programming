//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    string s;
    cin >> s;
    if (s.length() > 10)
        cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
    else
        cout << s << "\n";
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