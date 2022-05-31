/*
    Print SCS of 2 given strings
    s: "acbcf"
    t: "abcdaf"
    LCS: "abcf"
    SCS: "acbcdaf"
    The characters in LCS are used once, whereas other all characters are used, thus [len(SCS) = m + n - LCS]

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
    cin >> s >> t;
    ll n = ll(s.size()), m = ll(t.size());
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string SCS = "";
    ll x = n, y = m;
    while (x > 0 && y > 0) {
        if (s[x - 1] == t[y - 1]) {  // if equal characters, we move diagonally left, and add char
            SCS += s[x - 1];
            --x, --y;
        } else {
            if (dp[x - 1][y] > dp[x][y - 1]) {  // else we move towards larger value in dp table, and write both
                SCS += s[x - 1];                // add character before moving in the larger direction
                --x;
            } else {
                SCS += t[y - 1];
                --y;
            }
        }
    }
    // now we might have stopped somewhere else instead of the top left corner
    // so we need to add remaining characters
    while (x > 0) SCS += s[x - 1], --x;
    while (y > 0) SCS += t[y - 1], --y;
    reverse(all(SCS));
    cout << SCS << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
