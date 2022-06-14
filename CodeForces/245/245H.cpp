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

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp[i][j] = s[i, j] is palindrome
    for (int j = 0; j < n; ++j) {
        for (int i = j; i >= 0; --i) {
            if (i == j)
                dp[i][j] = 1;
            else if (j - i == 1)
                dp[i][j] = int(s[i] == s[j]);
            else if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
        }
    }
    // Now use 2D prefix_sum
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pref[i + 1][j + 1] =
                pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + dp[i][j];
        }
    }
    auto get = [&](int i, int j) {
        return pref[j][j] - pref[i - 1][j] - pref[j][i - 1] + pref[i - 1][i - 1];
    };
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << '\n';
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
