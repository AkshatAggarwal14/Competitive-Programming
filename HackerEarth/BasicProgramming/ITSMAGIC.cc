//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, sum = 0, flag = 0;
    cin >> n;
    ll arr[n], arr2[n] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll j = 0;
    for (ll i = 0; i < n; i++)
    {
        if ((sum - arr[i]) % 7 == 0)
        {
            flag = 1;
            arr2[j] = arr[i];
            j++;
        }
    }
    if (flag == 0) //! IF NOT FOUND
    {
        cout << "-1\n";
        return 0;
    }
    ll mini = *min_element(arr2, arr2 + j);
    ll ans = distance(arr, find(arr, arr + n, mini)); //!IMPORTANT
    cout << ans << "\n";
    return 0;
}