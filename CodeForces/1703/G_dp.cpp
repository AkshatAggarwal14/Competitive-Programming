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

void test() {
    ll n, cost;
    cin >> n >> cost;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<vector<ll>> dp(n + 1, vector<ll>(32));
    // dp[i][j] = max coins for chests from [i..n] with j bad keys left
    for (ll i = 0; i < 32; ++i) dp[n][i] = 0;  // empty set - no chests
    for (ll i = n - 1; i >= 0; --i) {
        for (ll j = 30; j >= 0; --j) {
            ll &ans = dp[i][j];
            // good key
            ans = max(ans, dp[i + 1][j] + (a[i] >> j) - cost);
            // bad key - divide this element and rest also
            ans = max(ans, dp[i + 1][j + 1] + (a[i] >> (j + 1)));
        }
    }
    cout << dp[0][0] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
