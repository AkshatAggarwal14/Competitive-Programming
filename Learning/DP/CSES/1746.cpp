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
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
    // dp[i][j] = number of array until index i matching description with last element being j
    function<ll(ll, ll)> dfs = [&](ll idx, ll last) {
        if (last <= 0 || last > m) return 0LL;  // as we can fill from [1, m]
        ll &ans = dp[idx][last];
        if (ans != -1) return dp[idx][last];
        if (a[idx] != 0 && a[idx] != last) return ans = 0;
        if (idx == 0) {
            return ans = 1;
        } else {
            return (ans = dfs(idx - 1, last - 1) + dfs(idx - 1, last) + dfs(idx - 1, last + 1)) %= MOD;
        }
    };

    ll ans = 0;
    for (ll i = 1; i <= m; ++i) (ans += dfs(n - 1, i)) %= MOD;
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
