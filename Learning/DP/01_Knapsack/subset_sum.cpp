/*
    arr[]: 2 3 7 8 10
    sum  : 11

    Q. Is there a subset in "arr[]" such that sum of the subset is equal to "sum"
    A. true/false
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

    // weight is given in arr, as it must sum up to "sum" i.e. capacity of knapsack
    // we have a choice, i.e. to include element or not from arr

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    // initialisation
    // dp[*][0] = subset of * size with zero sum is possible = empty subset = T
    // dp[0][sum] = empty subset with given sum = F
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int j = 1; j <= sum; ++j) dp[0][j] = false;

    // calculation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            // choice diagram - to include or not
            dp[i][j] = dp[i - 1][j];                                              // dont include or cant include
            if (arr[i - 1] <= j) dp[i][j] = dp[i][j] || (dp[i][j - arr[i - 1]]);  // include it
        }
    }

    if (dp[n][sum]) return void(cout << "possible\n");
    cout << "impossible\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}