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
    ll n, m;
    cin >> n >> m;
    vector<ll> wt(m + 1), val(m + 1), lim(m + 2);
    lim[m] = INF;            // no limit for this way
    cin >> wt[m] >> val[m];  // another way
    for (ll i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        lim[i] = a / b;
        cin >> wt[i] >> val[i];
    }
    vector<vector<ll>> dp(m + 2, vector<ll>(n + 1, -1));
    // dp[i][j] = max money earned by using i amount of dough on {1, 2, .., j} bun types
    auto dfs = [&](const auto &self, ll i, ll rem) {
        ll &ans = dp[i][rem];
        if (ans != -1) return ans;
        if (i == 0) return ans = 0;
        for (ll j = 0; j <= lim[i - 1] && j * wt[i - 1] <= rem; ++j) {
            ans = max(ans, j * val[i - 1] + self(self, i - 1, rem - j * wt[i - 1]));
        }
        return ans;
    };

    cout << dfs(dfs, m + 1, n) << '\n';
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
