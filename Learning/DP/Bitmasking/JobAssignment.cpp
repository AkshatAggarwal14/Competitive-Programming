// Given N workers and N jobs, find minimum cost to assign one worker to one job. (And one job to one woker). Given cost matrix, C[i][j] is cost of assigning j^th job to i^th person.
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int C[N][N], dp[N][1 << N];

/**
 * We have N possibilities to assign jobs to person 1.
 * We have N-1 ... to person 2.
 * ...
 * Thus naively, O(N!)
 */

/**
 * dp[i][mask]: minimum cost to assign people (in mask) to jobs i to N, such that available people are represented by the mask
 * (1, {1, 2, .. N}) = min(C[1][1] + (2, {2, 3, .. N}), C[2][1] + (2, {1, 3, .. N}), ...)
 * dp[i][mask] = for all valid j find minimum of (C[j][i] + dp[i + 1][mask with jth bit off])
 *
 * Number of states = N * 2^N
 * A state is independent of how you reach it!
 * Answer = dp[1][(1 << N) - 1] = minimum cost to assign jobs from 1 to N such that all people are available
 */

int dfs(int idx, int mask, int& n) {
    // no more jobs to assign
    if (idx == n) {
        return 0;
    }

    int& ans = dp[idx][mask];
    if (ans != -1) return ans;

    ans = INT_MAX;
    for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
            // jth person is available
            int tans = C[j][idx] + dfs(idx + 1, mask ^ (1 << j), n);
            ans = min(ans, tans);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> C[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, (1 << n) - 1, n) << '\n';
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