//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll x, a, b;
    cin >> x >> a >> b;
    if (x >= 31 && x <= 40 && a >= 101 && a <= 120 && b >= 1 && b <= 5)
        cout << (a + (100 - x) * b) * 10 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    if (t >= 1 && t <= 1000)
        while (t--)
        {
            solve();
        }
    return 0;
}