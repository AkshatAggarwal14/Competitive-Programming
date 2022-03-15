/*
    length[]: 1 2 3 4 5  6  7  8
    price[]:  1 5 8 9 10 17 17 20
    Given a rod, and price for a rod of given length, maximise profit after cutting rod into several pieces
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

// sometimes len[] array is eliminated and price[i] gives price for length = i

void test() {
    int n, length;  // n -> W
    cin >> n >> length;
    vector<int> price(n), len(n);  // price[] -> val[], len[] -> wt[]
    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> len[i];

    vector<vector<int>> dp(n + 1, vector<int>(length + 1, -1));
    // dp[i][j] = max profit from first i items in len[] to cut rod of length j into

    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    for (int i = 0; i <= length; ++i) dp[0][i] = 0;

    // iterative calculation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= length; ++j) {
            dp[i][j] = dp[i - 1][j];  // didnt choose
            if (len[i - 1] <= j) {
                // here we have dp[i][j - wt[i - 1]] because we can choose same item again, until condition
                dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i][j]);
            }
        }
    }

    cout << dp[n][length] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
