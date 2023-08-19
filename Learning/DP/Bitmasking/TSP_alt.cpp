#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 1e9;
int dist[N][N], dp[1 << N][N];

int main() {
    // dp[mask][i] = minimum distance to travel to visit the cities in mask from index i
    // dp[0][i] = dist[0][i] (distance to return to city 0 from i, if no more cities to visit)

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int idx = 0; idx < N; ++idx) {
            if (mask == 0)
                dp[mask][idx] = dist[0][idx];
            else
                dp[mask][idx] = INF;
        }
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int idx = 0; idx < N; ++idx) {
            for (int bit = 0; bit < N; ++bit) {
                if ((mask >> bit) & 1) {
                    if (bit != idx) {
                        dp[mask][idx] = min(dp[mask][idx], dp[mask ^ (1 << bit)][bit] + dist[idx][bit]);
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << '\n';
}

/**
4
0 10 15 20
10 0 25 25
15 25 0 30
20 25 30 0

Output: 80
*/