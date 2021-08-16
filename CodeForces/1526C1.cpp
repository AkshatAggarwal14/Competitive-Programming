#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    repn(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<ll>());
    ll ans = 0, health = 0;
    repn(i, n)
    {
        health += arr[i];
        if (health < 0)
            break;
        ans++;
    }
    cout << ans << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}