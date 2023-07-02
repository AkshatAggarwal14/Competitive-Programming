#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        // dp[i] = true if prefix of length {i} is interesting!
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            if (i + a[i] <= n && dp[i - 1]) dp[i + a[i]] = true;      // [len, [seq]]
            if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) dp[i] = true;  // [[seq], len]
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
}