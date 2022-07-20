#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[5002];
ll dp[5002][5002];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    // dp[L][R] = maximum answer for first player for range [L, R]
    // 1. a[L] + minimum answer after player 2 chooses an element
    // 2. a[R] + minimum answer after player 2 chooses an element
    for (int L = n - 1; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
            if (R <= L + 1) {
                dp[L][R] = max(a[L], a[R]);
            } else {
                dp[L][R] = max(a[L] + min(dp[L + 1][R - 1], dp[L + 2][R]), a[R] + min(dp[L][R - 2], dp[L + 1][R - 1]));
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}