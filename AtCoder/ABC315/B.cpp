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
    ll m;
    cin >> m;
    vector<ll> d(m);
    for (auto &x : d) cin >> x;
    ll sum = (accumulate(d.begin(), d.end(), 0LL) + 1) / 2;
    // cout << sum << '\n';
    for (ll i = 0; i < m; ++i) {
        if (sum > d[i]) {
            sum -= d[i];
        } else {
            ll more = sum;
            cout << i + 1 << ' ' << more << '\n';
            return;
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
