#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

const int MX = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<ll> h(n), dp(n, MX);
    for (auto& H : h) cin >> H;
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k and i - j >= 0; ++j) {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
