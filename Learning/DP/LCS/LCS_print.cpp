/*
    Print LCS of 2 given strings
    s: "abcef"
    t: "abfec"

    o/p: "abe"
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

    string lcs = "";
    ll x = n, y = m;
    while (dp[x][y]) {
        if (s[x - 1] == t[y - 1]) {  // if equal characters, we move diagonally left, and add char
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
