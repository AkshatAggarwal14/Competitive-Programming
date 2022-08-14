#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 20;
ll dp[N];
//? Tiling N x 3 grid using 1x3, 2x3, 3x3, 3x2, 3x1

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    /*
        1. horizontal line of height 1 - 3x1
        2. horizontal line of height 2 - 3x2
        3. horizontal line of length 3 - A) 3x3
                                         B) 1x3 + 2x3
                                         C) 2x3 + 1x3
                                         D) 1x3 + 1x3 + 1x3
    */
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    // dp[i] =  ways to fill until this line
    dp[1] = 1, dp[2] = 2, dp[3] = 7;
    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + 4 * dp[i - 3];
    }
    cout << dp[n] << '\n';
}