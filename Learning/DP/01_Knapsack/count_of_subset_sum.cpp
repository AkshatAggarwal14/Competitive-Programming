/*
    how many subsets in array with given sum?
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

void test() {
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;    // true
    for (int j = 1; j <= sum; ++j) dp[0][j] = 0;  // false

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (arr[i - 1] <= j) {                                    // will include
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];  // count subset of both types
            } else {                                                  // cant include
                dp[i][j] = dp[i - 1][j];                              // count of previous only
            }
        }
    }

    cout << dp[n][sum] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
6 10
2 3 5 6 8 10
*/