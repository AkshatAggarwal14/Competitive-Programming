#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    ll n = ll(s.size()), m = ll(t.size());
    // dp[i][j] = length of longest common subsequence for s[1, i] and t[1, j]
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                // remove last character
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string LCS = "";
    ll i = n, j = m;
    while (dp[i][j]) {
        if (s[i - 1] == t[j - 1]) {
            LCS += s[i - 1];
            // move diagonally
            --i, --j;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            // move to larger value
            --j;
        } else {
            --i;
        }
    }

    reverse(LCS.begin(), LCS.end());

    cout << LCS << '\n';

    return 0;
}
