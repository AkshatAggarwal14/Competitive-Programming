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

void test() {
    ll n;
    cin >> n;

    auto can = [&](ll k, ll x) {
        // k ^ (x + 1) - 1 / (k - 1)
        ll sum = 1, cur = 1;
        for (ll i = 1; i <= x; i++) {
            if (cur <= INF / k) {
                cur *= k;
            } else {
                // if this branching value overflows
                return LLONG_MAX;
            }
            sum += cur;
        }
        return sum;
    };

    // As n <= 1e18 and 2^60 > 1e18
    // max depth = 60
    for (int depth = 2; depth <= 60; ++depth) {
        ll L = 2, R = INF;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            ll query = can(M, depth);
            if (query <= n) {
                if (query == n) return void(cout << "YES\n");
                L = M;
            } else {
                R = M;
            }
        }
    }

    cout << "NO\n";
}

int32_t main() {
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
