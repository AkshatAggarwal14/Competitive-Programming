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
    ll a, b, c;
    cin >> a >> b >> c;

    if ((c != a + 1)) {
        return void(cout << "-1\n");
    }

    if (a == 0) {
        return void(cout << b << '\n');
    }

    ll h = __lg(a);
    ll leaves = a + 1;
    ll left = INF;
    for (ll cur = 1; cur <= 32; ++cur) {
        ll value = (1LL << cur) - 1;
        if (value <= a) {
            left = min(left, a - value);
        }
    }

    ll lastLevel = (1LL << h);
    ll moreNeeded = lastLevel - left;

    ll leavesForB = moreNeeded + left * 2;

    while (b >= leavesForB) {
        b -= leavesForB;
        ++h;
    }

    if (b > moreNeeded) {
        ++h;
    }

    ++h;  // due to c

    cout << h << '\n';
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
