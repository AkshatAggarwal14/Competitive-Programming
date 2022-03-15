/*
    how many subsets in array with given diff?
    S1 - S2 = diff
    S1 + S2 = sum
    --------------
    S1 = (diff + sum) / 2

    ! ALSO equivalent to target sum: assign signs to each array element to get given sum, count how many possible?
    so divide into 2 subsets S1 and S2, such that all elements in S1 are +ve, and S2 -ve, SO
    S1 - S2 = sum
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
    int n, target, sum = 0;
    cin >> n >> target;
    target = abs(target);  // if we can assign negative symbols [we can swap] and assign same positive
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];

    if ((sum + target) & 1) return void(cout << "0\n");
    int val = (target + sum) / 2;
    if (val > sum) return void(cout << "0\n");

    vector<vector<int>> dp(n + 1, vector<int>(val + 1, 0));
    for (int i = 0, cnt = 0; i <= n; ++i) {
        if (i > 0 && arr[i - 1] == 0) ++cnt;
        dp[i][0] = (1LL << cnt);  // can get large, thus %MOD is used
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= val; ++j) {
            dp[i][j] = dp[i - 1][j];  // subsets with sum = j, without ith element
            if (arr[i - 1] <= j)
                dp[i][j] += dp[i - 1][j - arr[i - 1]];  // add subsets with ith element
        }
    }

    cout << dp[n][val] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
6 10
2 3 5 6 8 10

ans: 1
diff = 10
sum  = 34
S1 = 22 [3 + 5 + 6 + 8]
S2 = 12 [2 + 10]

6 0
0 0 0 0 0 0

ans: 64
*/