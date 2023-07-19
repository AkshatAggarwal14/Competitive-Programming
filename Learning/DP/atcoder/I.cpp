#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<double> p(n);
    for (auto &x : p) cin >> x;
    // dp[i][h] = probability of getting h heads in i throws
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int h = 0; h <= i; ++h) {
            // ith throw was a tail + ith throw was a head
            dp[i][h] = dp[i - 1][h] * (1 - p[i - 1]) +
                       (h > 0 ? dp[i - 1][h - 1] * (p[i - 1]) : 0);
        }
    }

    double ans = 0;
    for (int h = n / 2 + 1; h <= n; ++h) {
        ans += dp[n][h];
    }

    cout << setprecision(10) << ans << '\n';

    return 0;
}
