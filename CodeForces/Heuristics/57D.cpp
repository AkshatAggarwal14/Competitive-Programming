#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    vector<ll> dp(366, 0);
    ll j = 0;
    for (ll i = 1; i < 366; i++) {
        dp[i] = 200 + dp[i - 1];
        if (i - 7 >= 0) dp[i] = min(dp[i - 7] + 700, dp[i]);
        if (i - 30 >= 0) dp[i] = min(dp[i - 30] + 1500, dp[i]);
        if (j < sz(a) && a[j] == i) {
            j++;
        } else {
            dp[i] = min(dp[i], dp[i - 1]);
        }
    }
    cout << dp[365] << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}