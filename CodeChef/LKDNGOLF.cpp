//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n, x, k;
    cin >> n >> x >> k;
    if (x >= 1 && x <= n && k >= 1 && k <= n && n >= 1 && n <= 1e9)
    {
        if ((x) % k == 0 || (n + 1 - x) % k == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    if (t >= 1 && t <= 1e5)
        while (t--)
        {
            solve();
        }
    return 0;
}