#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, h;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    cin >> h;
    sort(arr, arr + n, greater<ll>());
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] <= h)
        {
            cout << n - i + 1;
            break;
        }
    }
    return 0;
}