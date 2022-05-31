/*
    s: "AABEBCDD"
    Longest Repeating subsequence is "ABD" occuring twice with no overlapping characters.
    "AABEBCDD"
    "A_B____D"
    "_A__B_D_" [No character must be repeating]

    Same as LCS, with t = s, the only difference is when characters are same, index must not be same
    (i != j)
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s, t;
    cin >> s;
    t = s;
    ll n = ll(s.size());
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1] && i != j) {  // same char at different index
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string lcs = "";
    ll x = n, y = n;
    while (dp[x][y]) {
        if (s[x - 1] == t[y - 1] && x != y) {  // if equal characters, we move diagonally left, and add char only if on different index.
            lcs += s[x - 1];
            --x, --y;
        } else {
            if (dp[x - 1][y] >= dp[x][y - 1]) {  // else we move towards larger value in dp table
                --x;
            } else {
                --y;
            }
        }
    }
    reverse(all(lcs));
    cout << lcs << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
