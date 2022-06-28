#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, K;
    cin >> n >> K;
    vector<ll> h(n), dp(n, ll(1e9));
    for (auto& H : h) cin >> H;
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
        for (int k = 1; k <= K && i - k >= 0; ++k)
            dp[i] = min(dp[i], dp[i - k] + abs(h[i] - h[i - k]));
    cout << dp[n - 1] << '\n';
    return 0;
}
