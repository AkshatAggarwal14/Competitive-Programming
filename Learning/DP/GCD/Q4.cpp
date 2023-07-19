// https://leetcode.com/problems/number-of-different-subsequences-gcds/description/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1'00'000, MOD = 1e9 + 7;

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), cnt(N + 1, 0), dp(N + 1, 0);

    for (auto &x : a) cin >> x, ++cnt[x];

    // dp[x] = number of subsequences with gcd x
    // dp[x] = Number of subsequences such that all elements are divisible by x - Number of subsequences with gcd 2x - ...

    int ans = 0;
    for (int i = N; i >= 1; --i) {
        // if nothing to subtract
        int cur = cnt[i];
        // subtract all with gcd 2x, 3x, 4x, ..
        for (int j = 2 * i; j <= N; j += i) {
            cur += cnt[j];
            dp[i] = (dp[i] - dp[j]) % MOD;
            dp[i] += MOD;
            dp[i] %= MOD;
        }

        dp[i] = (dp[i] + (((power(2, cur) - 1) % MOD) + MOD) % MOD) % MOD;  // number of subsequences
        if (dp[i]) ++ans;
    }

    cout << ans << '\n';
}