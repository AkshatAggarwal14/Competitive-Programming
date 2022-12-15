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
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s += '0';
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    // dp[i][0] = ans for [i..n] if s[i] = 0
    // dp[i][1] = ans for [i..n] if s[i] = 1

    // we have cases:   1. s[i] = 1, then we just take it
    //                  2. s[i] = 0,
    //                              a. s[i + 1] = 0
    //                              b. s[i + 1] = 1 -> FURTHER CASES: we either make 10 to 01 or do nothing

    for (ll i = n - 1; i >= 0; --i) {
        if (s[i + 1] == '0') {
            dp[i][0] = dp[i + 1][0];
        } else {
            dp[i][0] = max(dp[i + 1][0] + a[i], dp[i + 1][1]);
        }
        dp[i][1] = dp[i + 1][s[i + 1] - '0'] + a[i];
    }
    cout << dp[0][s[0] - '0'] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
