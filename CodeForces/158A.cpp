//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll check = a[k - 1], ctr = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] >= check && a[i] > 0)
        {
            ctr++;
        }
    }
    cout << ctr << "\n";
    return 0;
}