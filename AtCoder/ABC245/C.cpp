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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    vector<vector<bool>> dp(n, vector<bool>(2, false));
    for (ll &A : a) cin >> A;
    for (ll &B : b) cin >> B;
    dp[0][0] = dp[0][1] = true;  // in (X1) can X1 = A1, Yes
    for (ll i = 1; i < n; ++i) {
        if (dp[i - 1][0]) {
            if (abs(a[i] - a[i - 1]) <= k) dp[i][0] = true;
            if (abs(b[i] - a[i - 1]) <= k) dp[i][1] = true;
        }
        if (dp[i - 1][1]) {
            if (abs(a[i] - b[i - 1]) <= k) dp[i][0] = true;
            if (abs(b[i] - b[i - 1]) <= k) dp[i][1] = true;
        }
    }
    cout << ((dp[n - 1][0] || dp[n - 1][1]) ? "Yes\n" : "No\n");
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
