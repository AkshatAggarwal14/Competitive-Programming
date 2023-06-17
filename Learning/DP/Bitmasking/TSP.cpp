/**
 * TSP is NP Hard - Best algorithm is still exponential.
 * Visit each city exactly once and come back to his home city - basically a tour
 * Task = Minimise the entire distance travelled
 * We have a distance matrix, d[i][j]
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 1e9;
int d[N][N], dp[N][1 << N];

/**
 * We have N possibilities to visit first city.
 * We have N-1 ... visit next city.
 * ...
 * Thus naively, O(N!)
 */

/**
 * dp[i][S]: minimum distance to travel from city i to the cities in the S are left to visit and then return to 0
 * (1, {1, 2, .. N}) = min(d[1][1] + (2, {2, 3, .. N}), d[1][2] + (2, {1, 3, .. N}), ...)
 * dp[i][S] = min{ dp[j][S - {j}] + distance[i][j] }
 *
 * Number of states = N * 2^N
 * Each state takes O(N) time to compute as we traverse through the mask.
 * Thus time complexity is O(N^2 * 2^N) and space complexity is O(N * 2^N)
 * A state is independent of how you reach it!
 * Answer = dp[0][(1 << N) - 1] = minimum distance to travel to visit cities from 1 to N such that all cities are left.
 */

int dfs(int idx, int mask, int& n) {
    // no more cities to visit
    if (mask == 0) {
        // return to home city 1
        return d[0][idx];
    }

    int& ans = dp[idx][mask];
    if (ans != -1) return ans;

    ans = INF;
    for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
            // jth city is not visited
            // visit city j from idx
            int tans = d[idx][j] + dfs(j, mask ^ (1 << j), n);
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
            cin >> d[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    // cost to return to city 0.
    cout << dfs(0, (1 << n) - 1, n) << '\n';
}

/**
4
0 10 15 20
10 0 25 25
15 25 0 30
20 25 30 0

Output: 80
*/