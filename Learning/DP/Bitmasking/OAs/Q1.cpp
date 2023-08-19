/**
Question:
Number of ways to choose elements that sum up to given value SUM, such that no two adjacent elements are of same groups. (Each element has a given value and a group number (0, 1 or 2))

Example
N=3, SUM = 4

(2,0)
(2,1)
(4,0)

Answer = 3
1. Choosing elements 1, 2
2. Choosing elements 2,1
3. Choosing elements 3

N <= 15, Sum <= 225, a[i] <= 15, g[i] <= 2
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1 << 15][4][226], a[15], g[15];

int main() {
    int N, SUM;
    cin >> N >> SUM;
    for (int i = 0; i < N; ++i) cin >> a[i] >> g[i];
    // dp[mask][last_group][sum_yet]

    memset(dp, 0, sizeof(dp));

    dp[0][3][0] = 1;

    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int bit = 0; bit < N; ++bit) {
            if (!((mask >> bit) & 1)) {
                for (int sum = 0; sum + a[bit] < 226; ++sum) {
                    for (int last = 0; last < 4; ++last) {
                        if (g[bit] != last) {
                            dp[mask | (1 << bit)][g[bit]][sum + a[bit]] += dp[mask][last][sum];
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int last = 0; last < 4; ++last) {
            ans += dp[mask][last][SUM];
        }
    }

    cout << ans << '\n';
}