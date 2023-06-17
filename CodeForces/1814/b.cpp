#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 2e9;
const ll N = 1e5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    // https://www.desmos.com/calculator/z8ihujqmwb
    ll a, b;
    cin >> a >> b;
    ll mid = ll(sqrt(a + b)), ans = INT_MAX;
    for (ll i = max(mid - 10000, 1LL); i <= min(mid + 10000, max(a, b)); ++i) {
        ans = min(ans, i - 1 + (a + i - 1) / i + (b + i - 1) / i);
    }
    cout << ans << '\n';
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
