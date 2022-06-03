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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i + 1; k < j; ++k)  // we break into 2 matrices [i, k - 1] and [k, j]
                dp[i][j] = min(dp[i][j], dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);
        }
    }
    cout << dp[0][n - 1] << '\n';  // in this version A[i] -> arr[i] * arr[i + 1]
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
