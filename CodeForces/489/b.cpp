#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 102;
int a[N], b[N], dp[N][N];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    // dp[i][j] = largest pairs possible for a[i..n] and b[j..m]
    dp[n][m] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int &ans = dp[i][j];
            if (abs(a[i] - b[j]) <= 1)
                ans = 1 + dp[i + 1][j + 1];  // use both
            ans = max(ans, dp[i + 1][j]);    // dont use a[i]
            ans = max(ans, dp[i][j + 1]);    // dont use b[j]
        }
    }
    cout << dp[0][0] << '\n';
}