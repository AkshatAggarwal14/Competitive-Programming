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
    // dp[i][j] = number of array until index i matching description with last element being j
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
    auto dfs = [&](const auto &self, ll i, ll last) -> ll {
        if (last <= 0 || last > m) return 0;
        ll &ans = dp[i][last];
        if (ans != -1) return dp[i][last];
        if (i == 0) {
            if (a[i] == 0 || a[i] == last) return ans = 1;
            return ans = 0;
        }
        if (a[i] != 0 && a[i] != last) return ans = 0;
        return (ans = self(self, i - 1, last - 1) +
                      self(self, i - 1, last) +
                      self(self, i - 1, last + 1)) %= MOD;
    };

    ll ans = 0;
    for (ll i = 1; i <= m; ++i) (ans += dfs(dfs, n - 1, i)) %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
