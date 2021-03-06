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
    for (int i = 0, cnt = 0; i <= n; ++i) {
        if (i > 0 && arr[i - 1] == 0) ++cnt;
        dp[i][0] = (1LL << cnt);  // can get large, thus %MOD is used
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];  // subsets with sum = j, without ith element
            if (arr[i - 1] <= j)
                dp[i][j] += dp[i - 1][j - arr[i - 1]];  // add subsets with ith element
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

ans: 3

6 0
0 0 0 0 0 0

ans: 64
*/