#include <bits/stdc++.h>
using namespace std;

// dp[mask][j] = count of numbers that can be made from given mask, such that they have sum % m = j

const int N = 18;
long long dp[1 << N][100];

int main() {
    int m;
    string s;
    cin >> s >> m;

    int n = int(s.size());

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int prevSum = 0; prevSum < m; ++prevSum) {
            bitset<10> used(0);  // to not count a newSum again
            for (int bit = 0; bit < n; ++bit) {
                int digit = (s[n - 1 - bit] - '0');

                if (!((mask >> bit) & 1)) {
                    if (used[digit] || (mask == 0 and digit == 0)) continue;
                    used[digit] = true;

                    int newSum = (prevSum * 10 + digit) % m;

                    dp[mask | (1 << bit)][newSum] += dp[mask][prevSum];
                }
            }
        }
    }

    // for (int mask = 0; mask < (1 << n); ++mask) {
    //     for (int sum = 0; sum < m; ++sum) {
    //         cout << "dp[ ";
    //         for (int i = 0; i < n; ++i) {
    //             if ((mask >> (n - 1 - i)) & 1) {
    //                 cout << s[n - 1 - i] << ' ';
    //             }
    //         }
    //         cout << "][" << sum << "] = " << dp[mask][sum] << '\n';
    //     }
    // }

    cout << dp[(1 << n) - 1][0] << '\n';
}
