//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    ll costg, costp;
    cin >> costg >> costp;
    ll n;
    cin >> n;
    ll mat[n][2], ctr[2] = {0};
    rep(i, 0, n)
    {
        cin >> mat[i][0] >> mat[i][1];
        ctr[0] += mat[i][0];
        ctr[1] += mat[i][1];
    }
    sort(ctr, ctr + 2);
    if (costg >= costp)
        cout << costg * ctr[0] + costp * ctr[1] << "\n";
    else if (costg < costp)
        cout << costp * ctr[0] + costg * ctr[1] << "\n";
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