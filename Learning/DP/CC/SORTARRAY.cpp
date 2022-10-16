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
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), mn(n + 1, INF), dp(n + 1, INF);
    dp[1] = 0;
    // dp[i] = min moves to sort prefix
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = min(dp[i], mn[a[i]] + 1);  // min value of dp in past + 1, if we have to apply this move
        if (a[i] >= a[i - 1])
            dp[i] = min(dp[i], dp[i - 1]);  // just move to next element
        if (a[i - 1] <= a[i])
            mn[a[i]] = min(mn[a[i]], dp[i]);  // update min value in prefix
    }
    if (dp[n] == INF) dp[n] = -1;
    cout << dp[n] << '\n';
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
