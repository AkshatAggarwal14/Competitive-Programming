/**
 *    author:  master._.mind
 *    created: 2022.06.21 03:13:25
 **/

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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    // draw tree downwards and notice
    vector<vector<ll>> dp(n), mx(n);
    for (int i = 0; i < n; ++i) dp[i].resize(n - i), mx[i].resize(n - i);
    dp[0] = a, mx[0] = a;
    for (int level = 1; level < n; ++level) {
        for (int i = 0; i < sz(dp[level]); ++i) {
            dp[level][i] = (dp[level - 1][i] ^ dp[level - 1][i + 1]);
        }
        for (int i = 0; i < sz(dp[level]); ++i) {
            mx[level][i] = max({mx[level - 1][i], mx[level - 1][i + 1],
                                dp[level][i]});
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << mx[r - l][l - 1] << '\n';
    }
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
