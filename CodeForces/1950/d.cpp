#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

array<bool, N> dp;

bool checkBinaryDecimal(ll num) {
    while (num) {
        ll last = num % 10;
        if (last != 0 and last != 1) return false;
        num /= 10;
    }
    return true;
}

void test() {
    ll n;
    cin >> n;
    cout << (dp[n] ? "YES\n" : "NO\n");
}

int32_t main() {
    dp[0] = dp[1] = true;
    for (ll i = 2; i < N; ++i) {
        dp[i] = false;
        if (checkBinaryDecimal(i)) {
            dp[i] = true;
        }
        for (ll j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ll ans = dp[j] and dp[i / j];
                dp[i] |= ans;
                if (ans) break;
            }
        }
    }
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
