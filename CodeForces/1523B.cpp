//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << 3 * n << "\n";
    for (int i = 1; i <= n; i += 2)
    {
        cout << 1 << " " << i << " " << i + 1 << "\n";
        cout << 2 << " " << i << " " << i + 1 << "\n";
        cout << 1 << " " << i << " " << i + 1 << "\n";
        cout << 2 << " " << i << " " << i + 1 << "\n";
        cout << 1 << " " << i << " " << i + 1 << "\n";
        cout << 2 << " " << i << " " << i + 1 << "\n";
    }
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