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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &it : a) cin >> it, it %= 2;
    for (auto &it : b) cin >> it;
    vector<vector<ll>> dp(2, vector<ll>(n, -1));
    // dp[player][position]
    auto dfs = [&](const auto &self, ll pos = 0, ll player = 0) -> ll {
        if (pos == n) return 0;
        ll &ans = dp[player][pos];
        if (ans != -1) return ans;
        ans = 0;
        ans = max(ans, self(self, pos + 1, player));
        if (a[pos]) {  // if odd, then only taking this can be beneficial
            if (player == 0) {
                // if alice takes, added to answer
                ans = max(ans, self(self, pos + 1, 1 - player) + b[pos]);
            } else {
                // if bob takes, subtracted from answer
                // bob is trying to minimize the value
                ans = min(ans, self(self, pos + 1, 1 - player) - b[pos]);
            }
        }
        return ans;
    };
    dbg(dp);
    cout << dfs(dfs) << '\n';
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
