#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // maximum sum after flipping a subarray
    constexpr int N = 102;
    int a[N], dp[N];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    /*
    // 1. sum from i..n, if we have already flipped the subarray: cant flip anymore
    // 2. sum from i..n, if we havent flipped and in subarray
    // 3. sum from i..n, if we havent flipped and not in subarray, can be started

    dp[n][0] = dp[n][1] = dp[n][2] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = max(dp[i + 1][0] + a[i], dp[i + 1][1] + a[i]);
        dp[i][1] = max(dp[i + 1][2] + 1 - a[i], dp[i + 1][1] + 1 - a[i]);
        dp[i][2] = dp[i + 1][2] + a[i];
    }
    cout << dp[0][0] << '\n';  // this is for atmost one move
    */

    //? answer = count(1) + maximum subarray sum in array such that a[i] = -1 when 1 and 1 when 0, as that is the effect of flipping a subarray
    dp[0] = ((a[0] == 0) ? 1 : -1);
    for (int i = 1; i < n; ++i) {
        int b = ((a[i] == 0) ? 1 : -1);
        dp[i] = max(b, dp[i - 1] + b);
    }
    cout << *max_element(dp, dp + n) + count(a, a + n, 1);
}