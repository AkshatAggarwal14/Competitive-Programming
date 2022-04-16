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

//  https://cs.stackexchange.com/questions/79263/count-arrays-with-size-n-sum-k-and-largest-element-m
const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 998244353;
void test() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
    dp[0][0] = 1;
    for (ll i = 1; i <= k; ++i) dp[0][i] = 0;
    auto dfs = [&](const auto &self, ll i, ll rem) {
        ll &ans = dp[i][rem];
        if (ans != -1) return ans;
        ans = 0;
        for (ll t = 1; t <= m; ++t) {
            if (rem - t >= 0) (ans += self(self, i - 1, rem - t)) %= MOD;
        }
        return ans;
    };
    ll sum = 0;
    for (ll i = 0; i <= k; ++i) (sum += dfs(dfs, n, i)) %= MOD;
    cout << sum % MOD << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
