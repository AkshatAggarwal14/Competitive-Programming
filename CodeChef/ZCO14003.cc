//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<ll>());
    ll max = arr[0];
    for (ll i = 0; i < n; i++)
        if (arr[i] * (i + 1) >= max)
            max = arr[i] * (i + 1);
    if (n >= 1 && n <= 5e5)
        cout << max << endl;
    return 0;
}