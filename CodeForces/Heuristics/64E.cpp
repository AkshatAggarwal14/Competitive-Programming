#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
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
    ll n = sz(s), twos = 1;
    vector<ll> dp(n + 1);
    // dp[i] = ans for prefix [0..i]
    // dp[i] = 1. Dont take current dig = dp[i - 1]
    //         2. take curr = dp[i - 1] * 10 + power(2, i) * s[i]
    // Ans: sum of all subsequences - the number
    for (ll i = 1; i <= n; ++i) {
        (dp[i] = 11 * dp[i - 1] + twos * (s[i - 1] - '0')) %= MOD;
        (twos *= 2) %= MOD;
    }
    ll ans = dp[n], tens = 1, last = 0;
    for (ll i = n - 1; i >= 0; --i) {
        (last += (tens * (s[i] - '0'))) %= MOD;
        (tens *= 10) %= MOD;
    }
    cout << (ans - last + MOD) % MOD << '\n';
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
