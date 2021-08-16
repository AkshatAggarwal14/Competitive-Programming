//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    string str;
    cin >> str;
    ll ctr[10] = {0};
    rep(i, 0, str.length())
    {
        ctr[str[i] - '0']++;
    }
    rep(i, 0, 10)
    {
        cout << i << " " << ctr[i] << "\n";
    }
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