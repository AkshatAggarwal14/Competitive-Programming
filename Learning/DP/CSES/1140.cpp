#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // there are 2 choices for each project:    1. Skip it and do [1..P_(N - 1)] -> dp[n] = dp[n - 1]
    //                                          2. Do it and find the largest project P_X, such that ending point of project is less than starting point of Nth project, dp[n] = money[n] + dp[x]

    using ll = long long;
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    for (auto &[a, b, p] : v) cin >> a >> b >> p;
    // sort by end points
    sort(v.begin(), v.end(), [](const array<int, 3> &A, const array<int, 3> &B) { return A[1] < B[1]; });

    // dp[i] = largest possible reward for first i projects
    vector<ll> dp(n + 1);
    dp[0] = 0;  // no reward for no projects
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];  // not including this project
        int L = 0, R = i - 1;
        --L, ++R;
        while (R > L + 1) {
            int M = (R + L) / 2;
            if (v[M][1] < v[i - 1][0]) {
                L = M;
            } else {
                R = M;
            }
        }
        dp[i] = max(dp[i], v[i - 1][2] + dp[L + 1]);  // including this project
    }
    cout << dp[n] << '\n';
    return 0;
}
