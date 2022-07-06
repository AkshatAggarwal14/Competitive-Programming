#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;

void test() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<long long> dp(sum + 1, 0);
    // dp[i] = ways to make sum = i
    dp[0] = 1;
    for (int i = 1; i <= sum; ++i) {
        for (int& c : coins) {
            (dp[i] += ((i >= c) ? dp[i - c] : 0)) %= MOD;
        }
    }
    cout << dp[sum] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
