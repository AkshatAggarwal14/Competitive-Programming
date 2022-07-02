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
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) cin >> a[i], a[i] %= m;
    if (n > m) {  // pegionhole principle
        return void(cout << "YES\n");
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    // dp[i][j] = true if we can choose a subsequence until ith element, with sum modulo m = j
    for (ll i = 1; i <= n; ++i) dp[i][a[i]] = true;
    for (ll i = 2; i <= n; ++i) {
        for (ll j = 0; j < m; ++j) {
            dp[i][j] = dp[i][j] | dp[i - 1][j];  // to get subseq of len i - 1 with sum j
            dp[i][j] = dp[i][j] | dp[i - 1][(j - a[i] + m) % m];
        }
    }
    cout << (dp[n][0] ? "YES\n" : "NO\n");
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
