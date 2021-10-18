#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);
bool sort_on_second(pair<ll, ll> left, pair<ll, ll> right)
{
    return left.second < right.second;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        ans += 2 * arr[i].first;
    }
    sort(arr.begin(), arr.end(), sort_on_second);
    reverse(arr.begin(), arr.end());
    ll i = 0, j = n - 1;
    ll cur = 0;
    while (i <= j)
    {
        ll tar = arr[j].second;
        if (i == j)
        {
            ll can_take = arr[i].first;
            ll to_take = max(0ll, arr[i].second - cur);
            can_take = max(0ll, can_take - to_take);
            ans -= can_take;
            break;
        }
        else if (cur >= tar)
        {
            cur += arr[j].first;
            ans -= arr[j].first;
            j--;
        }
        else if (cur + arr[i].first <= arr[j].second)
        {
            cur += arr[i].first;
            arr[i].first = 0;
            i++;
        }
        else
        {
            ll to_take = arr[j].second - cur;
            cur += to_take;
            cur += arr[j].first;
            arr[i].first -= to_take;
            ;
            ans -= arr[j].first;
            j--;
        }
    }
    cout << ans << endl;
}
int main()
{
    FAST1;
    FAST2;
    ll t = 1;
    while (t--)
    {
        solve();
    }
}