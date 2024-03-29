#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
using ld = long double;

struct item {
    ld num, den, len;
    item(ld A = 0, ld B = 0, ld C = 0) : num(A), den(B), len(C) {}
    bool operator<(const item& other) const {
        ld a1 = num, b1 = den, d1 = sqrtl(len);
        ld a2 = other.num, b2 = other.den, d2 = sqrtl(other.len);

        return a1 * b2 * d1 * d2 - 1200 * b1 * b2 * d2 <
               a2 * b1 * d1 * d2 - 1200 * b1 * b2 * d1;
    }

#ifdef LOCAL
    friend string to_string(item i) {
        array<ld, 3> res = {i.num, i.den, i.len};
        return to_string(res);
    }
#endif
};

void test() {
    ll n;
    cin >> n;
    vector<ll> p(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> p[i];

    vector<item> dp(n + 1);
    for (ll i = 1; i <= n; ++i) {
        dp[i] = {double(p[i]), 1.0, 1.0};
    }

    for (ll i = 2; i <= n; ++i) {
        for (ll j = 1; j < i; ++j) {
            dp[i] = max(dp[i], dp[j]);
        }
        for (ll j = 1; j < i; ++j) {
            ld tnum = dp[j].num * 0.9 + double(p[i]);
            ld tlen = dp[j].len + 1;
            ld tden = dp[j].den * 0.9 + 1;
            item titem(tnum, tden, tlen);

            dp[i] = max(dp[i], titem);
        }
    }

    ld res = -DBL_MAX;
    for (ll i = 1; i <= n; ++i) {
        res = max(res, dp[i].num / dp[i].den - 1200 / sqrtl(dp[i].len));
    }

    cout << res << '\n';
    dbg(dp);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(20);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
