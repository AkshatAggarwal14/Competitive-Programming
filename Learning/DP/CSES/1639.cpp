/*
    Operations: 1. Insert a character
                2. Delete a character
                3. Replace a character
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    // dp[i][j] -> minimum ways to convert s[0..i] to t[0..j]
    function<ll(ll, ll)> dfs = [&](ll i, ll j) {
        if (i == -1 || j == -1) return max(i + 1, j + 1);  // max of length of other if one is empty
        /*
        if (i <= -1 && j <= -1) return 0LL;  // as "", ""
        if (i == -1) return j + 1;           // j inserts, as "", t[0, j]
        if (j == -1) return i + 1;           // i deletes, as s[0, i], ""
        */
        ll &ans = dp[i][j];
        if (ans != -1) return ans;
        if (s[i] == t[j]) {
            ans = dfs(i - 1, j - 1);
        } else {
            // replace
            ans = 1 + dfs(i - 1, j - 1);
            // delete ith
            ans = min(ans, 1 + dfs(i - 1, j));
            // insert at ith
            ans = min(ans, 1 + dfs(i, j - 1));
        }
        return ans;
    };
    cout << dfs(n - 1, m - 1) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
