#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, MOD;
    cin >> n >> MOD;

    auto add = [&](int a, int b) {
        return int((a * 1LL + b) % MOD);
    };
    auto mul = [&](int a, int b) {
        return int((a * 1LL * b) % MOD);
    };

    vector<int> dp(n + 1);
    // number of occurences of i in all values of n/i = n/i - n/(i + 1)
    dp[1] = 1;
    // 2 ways:  1. floor division to some value
    //          2. subtract some value
    int pre = 1;
    for (int i = 2; i <= n; ++i) {
        int ans = 0;
        for (int j = 1; j * j <= i; ++j) {
            ans = add(ans,
                      mul(dp[j], i / j - i / (j + 1)));
            if (i / j != j) {
                ans = add(ans,
                          mul(dp[i / j], i / (i / j) - i / ((i / j) + 1)));
            }
        }
        dp[i] = add(pre, ans);
        pre = add(pre, dp[i]);
    }
    cout << dp[n] << '\n';
}