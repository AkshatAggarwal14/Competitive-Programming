//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repeq(i, a, b) for (ll i = a; i <= b; i++)
#define repn(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;

void swap(ll *x, ll *y)
{
    ll z;
    z = *x;
    *x = *y;
    *y = z;
}

void solve()
{

    ll n;
    cin >> n;
    ll len = 2 * n;
    ll arr[len];
    repn(i, len)
    {
        cin >> arr[i];
    }

    sort(arr, arr + len);

    for (ll i = 1; i < len - 2; i += 2)
    {
        swap(arr[i], arr[i + 2]);
    }

    swap(arr[len - 2], arr[len - 1]);

    repn(i, len)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
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