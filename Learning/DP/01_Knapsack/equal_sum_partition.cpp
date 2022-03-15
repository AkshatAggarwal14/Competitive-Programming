/*
    arr[]: 1 5 11 5
    O/P  : True/False

    Can we divide into 2 subsets with equal sum?
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
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
    if (sum % 2) return void(cout << "impossible\n");  // as sum must be even for equal

    // sum1 == sum2, sum1 = sum2 = sum / 2
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int j = 1; j <= sum / 2; ++j) dp[0][j] = false;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum / 2; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i][j] || (dp[i - 1][j - arr[i - 1]]);
        }
    }
    cout << ((dp[n][sum / 2]) ? "possible\n" : "impossible\n");
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
4
1 5 11 5
*/