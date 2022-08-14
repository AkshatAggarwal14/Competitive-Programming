#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 998244353;

void test() {
    // dp[i] = time taken to cross ith portal if its open
    // dp[i] = dist[i] + cost[i]
    // dist[i] = y[i] - x[i]
    // cost[i] = sum of all dp[j] such that x[j] > x[i]
    // any portal before ants position will always be open
    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
    }
    vector<int> dp(n), pre(n + 1);
    for (int i = 0; i < n; ++i) {
        int k = lower_bound(all(x), y[i]) - x.begin();
        dp[i] = (pre[i] - pre[k] + x[i] - y[i]) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
        pre[i + 1] = (pre[i] + dp[i]) % MOD;
    }
    int ans = x[n - 1] + 1;  // to reach x_n + 1
    ans %= MOD;
    for (int i = 0; i < n; ++i) {
        if (s[i]) {
            ans += dp[i];
            ans %= MOD;
        }
    }
    cout << ans << '\n';
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
