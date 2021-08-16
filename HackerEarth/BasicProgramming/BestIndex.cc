//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, arr[100000], temp;
    cin >> n;
    cin >> arr[0];
    rep(i, 1, n)
    {
        cin >> temp;
        arr[i] = temp + arr[i - 1];
    }
    ll ans = -10000000, sum = 0;
    rep(i, 0, n)
    {
        ll x = n - i, sum = 0;
        for (ll a = 1; x >= a; a++)
            x -= a;
        sum = arr[n - x - 1] - arr[i - 1];
        if (sum > ans)
            ans = sum;
    }

    cout << ans;
    return 0;
}

/*
!MY SOLUTION
//*use cout<<"\n" instead of endl as endl is slower
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
*/