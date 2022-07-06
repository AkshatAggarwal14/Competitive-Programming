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
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    // dp[i][j] = true if we can create sum j using first i elements
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int j = 1; j <= sum; ++j) dp[0][j] = false;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];  // dont include or cant include
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i][j] || (dp[i - 1][j - arr[i - 1]]);  // include it
        }
    }

    vector<int> included;
    for (int i = 1; i <= sum; ++i)
        if (dp[n][i]) included.push_back(i);
    cout << sz(included) << '\n';
    for (auto &x : included) cout << x << ' ';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
