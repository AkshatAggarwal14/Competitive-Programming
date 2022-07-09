#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    //! find max subarray sum if you can square any two value of the array
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));

    /*
    ? States
        dp[i] = max subarray sum ending for first i elements
        dp[i][0] = squared 2 values in [0..i]
        dp[i][1] = squared 1 value in [0..i]
        dp[i][2] = squared no values in [0..i]
    ? Recurrences
        dp[i][0] =>     1. a[i]
                        2. a[i] + dp[i - 1][0] {already squared 2 values}
                        3. a[i] * a[i] + dp[i - 1][1] {Squared this value and one was squared before}
        => no need of only a[i] * a[i] option here as optimally we dont break the subarray where we squared the elements

        dp[i][1] =>     1. a[i]
                        2. a[i] + dp[i - 1][1] {already squared 1 value}
                        3. a[i] * a[i]
                        4. a[i] * a[i] + dp[i - 1][2] {Squared this value, and none was squared before}

        dp[i][2] =>     1. a[i]
                        2. a[i] + dp[i - 1][2] {None was squared before}
    */
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        dp[i][0] = max(a[i] + max(dp[i - 1][0], 0LL),
                       a[i] * a[i] + dp[i - 1][1]);  // optimally no need for max with 0 here
        dp[i][1] = max(a[i] + max(dp[i - 1][1], 0LL),
                       a[i] * a[i] + max(dp[i - 1][2], 0LL));
        dp[i][2] = a[i] + max(0LL, dp[i - 1][2]);

        ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();    
    return 0;
}