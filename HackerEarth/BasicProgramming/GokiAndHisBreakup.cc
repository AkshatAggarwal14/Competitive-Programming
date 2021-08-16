//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    ll y[n];
    rep(i, 0, n)
    {
        cin >> y[i];
        if (y[i] >= x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}