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

/*
    For a question, i -> if t[i] > w -> cant include
                            t[i] <= w -> can include, val is c[i]*p[i]
                                      -> wont include
*/

void test() {
    ll n, w;
    cin >> n >> w;
    vector<ll> p(n), c(n), t(n);
    for (ll i = 0; i < n; ++i) cin >> c[i] >> p[i] >> t[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -1));
    auto dfs = [&](const auto &self, ll i, ll rem) -> ll {
        ll &ans = dp[i][rem];
        if (ans != -1) return ans;
        if (i == 0) return ans = 0;
        ans = self(self, i - 1, rem);  // cant or wont include
        if (t[i - 1] <= rem)
            ans = max(ans, (c[i - 1] * p[i - 1]) + self(self, i - 1, rem - t[i - 1]));
        return ans;
    };
    cout << dfs(dfs, n, w) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
