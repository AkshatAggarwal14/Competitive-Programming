// https://codeforces.com/contest/16/problem/E
#include <bits/stdc++.h>
using namespace std;

const int N = 19;
double p[N][N], dp[1 << N][N];
// dp[mask][i] = probability that i survives in the given mask

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            dp[mask][i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = __builtin_popcount(mask);
        if (cnt == 1) continue;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                double sum = 0;
                for (int bit = 0; bit < n; ++bit) {
                    if (i != bit and ((mask >> bit) & 1)) {
                        // probability that bit wins in mask = probability that all bit win from i in submask
                        sum += p[bit][i];
                    }
                }
                for (int bit = 0; bit < n; ++bit) {
                    dp[mask][bit] += sum * dp[mask ^ (1 << i)][bit] * 2.0 / (cnt * (cnt - 1));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dp[(1 << n) - 1][i] << ' ';
    }
    cout << '\n';
}