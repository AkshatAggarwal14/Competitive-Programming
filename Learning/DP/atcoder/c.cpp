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
    int n;
    cin >> n;
    vector<array<ll, 3>> a(n), dp(n);
    for (auto &[A, B, C] : a) cin >> A >> B >> C;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
    return 0;
}
