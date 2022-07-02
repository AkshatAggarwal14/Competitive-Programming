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
    ll n, q;
    cin >> n >> q;
    vector<ll> dp(n + 1, INF);
    dp[1] = 0;  // dp[i] = cost to reach i from 1
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 2 * i; j <= n; j += i) {
            dp[j] = min(dp[j], j / i + dp[i]);
        }
    }
    while (q--) {
        ll u, v;
        cin >> u >> v;
        // LCA
        cout << dp[u] + dp[v] - 2 * dp[gcd(u, v)] << '\n';
    }
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
