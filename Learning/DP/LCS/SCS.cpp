/*
    SCS = Shortest Common Supersequence
    Generate shortest string that contains both as subsequences

    Ex:
        s: "geek"
        t: "eke"
        SCS: "geeke"

    In worst case: len(SCS) = len(s) + len(t)
                            = m + n
    LCS is common to both and thus we can take advantage of characters in LCS.
    So, len(SCS) = m + n - len(LCS(s, t))
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
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    // dp[i][j] = length of longest subsequence in s[1..i] and t[1..j]
    auto dfs = [&](const auto &self, ll i, ll j) -> ll {
        ll &ans = dp[i][j];
        if (ans != -1) return ans;
        if (i == 0 || j == 0) return ans = 0;
        if (s[i - 1] == t[j - 1]) return ans = 1 + self(self, i - 1, j - 1);  // as char common to both
        return ans = max(self(self, i - 1, j), self(self, i, j - 1));         // remove one letter both strings
    };
    // SCS
    cout << n + m - dfs(dfs, n, m) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
