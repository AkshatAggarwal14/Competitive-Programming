/*
    arr[]: 1 6 11 5
    O/P  : 1

    minimum subset sum difference =>
    S1 - S2 = Minimum
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const ll INF = 1e9;

void test() {
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));
    // check until half, as sum - half will complement it
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int j = 1; j <= sum / 2; ++j) dp[0][j] = false;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum / 2; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i][j] || (dp[i - 1][j - arr[i - 1]]);
        }
    }

    for (int j = sum / 2; j >= 0; --j) {
        if (dp[n][j]) {  // largest possible subset sum gives answer to minimise sum - 2 * j
            cout << abs(sum - 2 * j) << '\n';
            return;
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
/*
4
1 6 11 5

ans: 1
*/