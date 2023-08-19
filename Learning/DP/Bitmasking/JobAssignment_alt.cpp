// Given N workers and N jobs, find minimum cost to assign one worker to one job. (And one job to one woker). Given cost matrix, C[i][j] is cost of assigning j^th job to i^th person.
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int C[N][N], dp[N][1 << N];

/**
 * dp[i][mask]: minimum cost to assign people (in mask) to jobs i to N, such that available people are represented by the mask
 * (1, {1, 2, .. N}) = min(C[1][1] + (2, {2, 3, .. N}), C[2][1] + (2, {1, 3, .. N}), ...)
 * dp[i][mask] = for all valid j find minimum of (C[j][i] + dp[i + 1][mask with jth bit off])
 *
 * Answer = dp[1][(1 << N) - 1] = minimum cost to assign jobs from 1 to N such that all people are available
 */

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> C[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    // if no more jobs to assign, put 0 in dp
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int j = 0; j < n; ++j) {
            dp[mask][j] = INT_MAX;
        }
    }

    // dp[mask][j] = cost of assigning jobs from [j..N] to the people inside mask
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int bit = 0; bit < n; ++bit) {
            if ((mask >> bit) & 1) {
                // bit^th person is available
                for (int j = 0; j < n; ++j) {
                    // assign jth job to bit^th person
                    dp[mask][j] = min(dp[mask][j], dp[mask ^ (1 << bit)][j + 1] + C[bit][j]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << '\n';
}

/**
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

Output: 13
P1 - Job2 (2)
P2 - Job1 (6)
P3 - Job3 (1)
P4 - Job4 (4)
*/