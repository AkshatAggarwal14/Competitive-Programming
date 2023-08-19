// https://codeforces.com/contest/16/problem/E
#include <bits/stdc++.h>
using namespace std;

const int N = 19;
double p[N][N], dp[1 << N];
// dp[mask][i] = probability that i survives in the given mask

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    // dp[mask] = probability to reach mask from 111...
    dp[(1 << n) - 1] = 1;
    // kill off one fish in mask
    for (int mask = (1 << n) - 2; mask >= 1; --mask) {
        int cnt = __builtin_popcount(mask) + 1;  // this mask + extra bit that we set
        for (int bit = 0; bit < n; ++bit) {
            if (!((mask >> bit) & 1)) {
                // if this bit is unset, this fish was killed by any of the others
                double sum = 0;
                for (int i = 0; i < n; ++i) {
                    if (i != bit && ((mask >> i) & 1)) {
                        sum += p[i][bit];
                    }
                }
                // total / C(cnt, 2) => all fish can fight with each other with equal probability
                dp[mask] += sum * dp[mask | (1 << bit)] * 2.0 / (cnt * (cnt - 1));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dp[1 << i] << ' ';
    }

    cout << '\n';
}