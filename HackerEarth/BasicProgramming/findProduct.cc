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
    ll p = 1;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        p = (p * temp) % ((ll)(1e9 + 7));
    }
    cout << p;
    return 0;
}