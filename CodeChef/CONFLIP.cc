//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    int g, n, q, i;
    cin >> g;
    while (g--)
    {
        cin >> i >> n >> q;
        if (n % 2 == 0)
            cout << n / 2;
        else
        {
            if (i == q)
                cout << (n - 1) / 2;
            else
                cout << (n + 1) / 2;
        }
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