/*
    coins[]: 1 2 3
    sum    : 5
    ways   : [2 3] [1 2 2] [1 1 3] [1 1 1 1 1] [1 1 1 2] ...
    minimum coins: [2 3] -> 2
    How many minimum number of coins needed to make given sum?

    For every coin, we have a choice to include or not include and IF we include, we can include multiple - unbounded

    W -> sum
    coins[] -> wt[]
*/

#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const int INF = 1e9;

void test() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<int> dp(sum + 1), coinVal(sum + 1);
    dp[0] = 0;

    for (int x = 1; x <= sum; x++) {
        dp[x] = INF;
        for (auto c : coins) {
            if (x - c >= 0 && dp[x - c] + 1 < dp[x]) {
                dp[x] = dp[x - c] + 1;
                coinVal[x] = c;
            }
        }
    }

    if (dp[sum] == INF) return void(cout << "-1\n");
    cout << dp[sum] << '\n';

    int t = sum;
    while (t > 0) {
        cout << coinVal[t] << ' ';
        t -= coinVal[t];
    }

    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
3 5
1 3 4

*/
