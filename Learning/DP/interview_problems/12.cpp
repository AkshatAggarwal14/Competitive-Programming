// https://www.geeksforgeeks.org/count-of-integers-obtained-by-replacing-in-the-given-string-that-give-remainder-5-when-divided-by-13/
// Count of integers obtained by replacing ? in the given string that give remainder 5 when divided by 13

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;  // 998244353

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = int(s.size());

    // dp[i][j] = count of integers obtained by replacing ? that give remainder j when divided by 13 in s[1, i]
    // dp[i][(10 * j + k) % 13] += dp[i - 1][j] and 0 <= k < 10
    vector<vector<int>> dp(n + 1, vector<int>(13, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> digits;
        if (s[i - 1] == '?') {
            digits.resize(10);
            iota(digits.begin(), digits.end(), 0);
        } else {
            digits.push_back(s[i - 1] - '0');
        }

        for (int &digit : digits) {
            for (int j = 0; j < 13; j++) {
                // j - oldRemainder, nj - newRemainder
                int nj = (10 * j + digit) % 13;
                dp[i][nj] += dp[i - 1][j];
                dp[i][nj] %= MOD;
            }
        }
    }
    cout << dp[n][5] << '\n';
    return 0;
}
