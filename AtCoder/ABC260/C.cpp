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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<array<ll, 2>> dp(n + 1);
    dp[1][0] = 0;  // [0] -> red
    dp[1][1] = 1;  // [1] -> blue
    for (int i = 2; i <= n; ++i) {
        dp[i][1] = (dp[i - 1][0] + (y * dp[i - 1][1]));
        dp[i][0] = (dp[i - 1][0] + (x * dp[i][1]));
    }
    cout << dp[n][0] << '\n';
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
