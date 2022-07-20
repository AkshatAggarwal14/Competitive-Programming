#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[5002][5002];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    // dp[i][k] -> max total sum if we take subarray starting at i and it is the kth chosen subarray
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    auto get = [&](int l, int r) { return pref[r + 1] - pref[l]; };

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= k; ++j) {
            // subarray not chosen
            dp[i][j] = dp[i + 1][j];
            // subarray chosen
            if (i + m <= n) dp[i][j] = max(dp[i][j], dp[i + m][j - 1] + get(i, i + m - 1));
        }
    }
    cout << dp[0][k] << '\n';
}