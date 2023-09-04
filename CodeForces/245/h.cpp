#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<vector<int>> isPalindrome(n, vector<int>(n, 0));
    // dp[i][j] = s[i, j] is palindrome
    for (int j = 0; j < n; ++j) {
        for (int i = j; i >= 0; --i) {
            if (i == j)
                isPalindrome[i][j] = 1;
            else if (j - i == 1)
                isPalindrome[i][j] = int(s[i] == s[j]);
            else if (s[i] == s[j])
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
        }
    }
    // dp2[i][j]: total sequence in range l to r
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            // [i, i+1,...j-1, j]
            // [i...j-1] + [i+1...j] - [i+1...j-1] <- double count
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + isPalindrome[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
