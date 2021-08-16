//*use cout<<"\n" instead of endl as endl is slower
//! only works until test case 4
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

ll sumTillN(ll n)
{
    if (n == 0)
        return 0;
    return (n * (n + 1)) / 2;
}

ll specialSum(ll arr[], ll size, ll index)
{
    ll k = 0, s = 0;
    while (index + sumTillN(k) - size <= 0)
    {
        for (ll i = 0; i - k < 0; i++)
        {
            s += arr[index + i + sumTillN(k - 1)];
        }
        k++;
    }
    return s;
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    ll sum[n];
    rep(i, 0, n)
    {
        sum[i] = specialSum(arr, n, i);
    }
    ll maxi = *max_element(sum, sum + n);
    cout << maxi << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}