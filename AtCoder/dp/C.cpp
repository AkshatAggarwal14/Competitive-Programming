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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    // dp[i][j] = max points for jth activity on last day [1, i]
    vector<array<ll, 3>> points(n);
    for (auto &a : points) {
        for (auto &el : a) {
            cin >> el;
        }
    }
    auto dp = points;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            ll add = 0;
            for (int k = 0; k < 3; ++k) {
                if (j != k && i > 0) {
                    add = max(add, dp[i - 1][k]);
                }
            }
            dp[i][j] += add;
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';

    return 0;
}
