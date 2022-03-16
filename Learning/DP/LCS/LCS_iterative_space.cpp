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

const ll N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s, t;
    cin >> s >> t;
    ll n = ll(s.size()), m = ll(t.size());
    vector<ll> dp(m + 1, 0), ndp(m + 1, 0);  // initialize 0
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                ndp[j] = 1 + dp[j - 1];
            } else {
                ndp[j] = max(ndp[j - 1], dp[j]);
            }
        }
        dp = ndp;
    }
    cout << dp[m] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
