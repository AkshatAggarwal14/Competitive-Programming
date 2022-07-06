#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const int MOD = 1e9 + 7;

void test() {
    int n, sum;
    cin >> n;
    sum = n * (n + 1) / 2;
    if (sum & 1) return void(cout << "0\n");
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));
    // dp[i][j] = ways to get sum j using first i elements i.e. [1..i]
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;  // sum 0 with first i elements

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum / 2; ++j) {
            dp[i][j] = dp[i - 1][j];  // subsets with sum j, without ith element
            if (i <= j)
                (dp[i][j] += dp[i - 1][j - i]) %= MOD;  // sum j with ith element
        }
    }
    // dp[n - 1][sum / 2] as now we fix 1 element in second subset, so we dont count twice
    cout << dp[n - 1][sum / 2] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}