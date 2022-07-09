/*
Find the number of lists that exist and satisfy the following:
    1.  list contains exactly 'N' elements
    2.  all elements of the list are between 'low' and 'high'
    3.  sum of all elements is even

Return answer modulo 10^9+7

Constraints
1 <= n <= 10^6
1 <= low <= high <= 10^6

Sample
(n=3,low=1,high=2) -> 4
(n=2,low=1,high=10) -> 50
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

int32_t main() {
    ll n, low, high;
    cin >> n >> low >> high;
    vector<ll> cnt(2);
    for (ll i = low; i <= high; ++i) ++cnt[i & 1];

    /*
    ? RECURSIVE

    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    // dp[i][0] = ways to fill [0, i] with even sum
    // dp[i][1] = ways to fill [0, i] with odd sum
    function<ll(ll, ll)> dfs = [&](ll i, ll parity) {
        if (i == 0) return cnt[parity];
        // odd change parity
        ll op1 = cnt[1] * dfs(i - 1, parity ^ 1);
        // even keeps same
        ll op2 = cnt[0] * dfs(i - 1, parity);
        return (op1 % MOD + op2 % MOD) % MOD;
    };
    cout << dfs(n - 1, 0) << '\n';
    */

    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    dp[0][0] = cnt[0], dp[0][1] = cnt[1];
    for (ll i = 1; i < n; ++i) {
        dp[i][0] = cnt[1] * dp[i - 1][1] + cnt[0] * dp[i - 1][0];
        dp[i][1] = cnt[1] * dp[i - 1][0] + cnt[0] * dp[i - 1][1];
    }
    cout << dp[n - 1][0] << '\n';
    return 0;
}
