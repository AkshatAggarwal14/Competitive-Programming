/*
    s: "abcde"
    t: "abfce"

    LCSub = "ab"
    o/p: 2
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
const ll N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s, t;
    cin >> s >> t;
    ll n = ll(s.size()), m = ll(t.size());
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    // dp[i][j] = length of longest substring in s[1..i] and t[1..j]
    // initialisation
    for (ll i = 0; i <= n; ++i) dp[i][0] = 0;
    for (ll j = 0; j <= m; ++j) dp[0][j] = 0;

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];  // no need for other case
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
