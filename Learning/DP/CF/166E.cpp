#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e7 + 5;
const ll MOD = 1e9 + 7;
ll dp[2][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    /*
    ? M1
    // dp[i][0] = currently at A at ith step
    // dp[i][1] = currently at B at ith step
    // dp[i][2] = currently at C at ith step
    // dp[i][3] = currently at D at ith step
    for (int i = 0; i < 4; ++i) dp[0][i] = dp[1][i] = 0;
    dp[0][3] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i % 2][0] = dp[(i + 1) % 2][1] + dp[(i + 1) % 2][2] + dp[(i + 1) % 2][3];
        dp[i % 2][1] = dp[(i + 1) % 2][0] + dp[(i + 1) % 2][2] + dp[(i + 1) % 2][3];
        dp[i % 2][2] = dp[(i + 1) % 2][1] + dp[(i + 1) % 2][0] + dp[(i + 1) % 2][3];
        dp[i % 2][3] = dp[(i + 1) % 2][1] + dp[(i + 1) % 2][2] + dp[(i + 1) % 2][0];
    }
    cout << dp[n & 1][3] << '\n';
    */

    //? M2 - symmetry of A, B, C from M1.
    // dp[i][0] = ways to be at top of tetrahedron after i moves
    // dp[i][1] = at one of the lower ones
    dp[0][0] = 1;
    dp[0][1] = dp[1][0] = dp[1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i & 1][0] = (3 * dp[(i + 1) & 1][1]) % MOD;
        dp[i & 1][1] = (2 * dp[(i + 1) & 1][1] + dp[(i + 1) & 1][0]) % MOD;
    }
    cout << dp[n & 1][0];
}