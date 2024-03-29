#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const int INF = 1e9;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // dp = minimum deletions [i..n-1]
    vector<array<int, 2>> dp(n + 1, {INF, INF});  // {element taken, skipped}
    dp[n] = {0, 0};
    for (int i = n - 1; i >= 0; --i) {
        int nxt = i + a[i] + 1;
        if (nxt <= n) {
            dp[i][0] = min(dp[nxt][0], dp[nxt][1]);
        }
        dp[i][1] = 1 + min(dp[i + 1][0], dp[i + 1][1]);
    }

    cout << min(dp[0][0], dp[0][1]) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
