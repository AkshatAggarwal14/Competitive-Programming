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
    // Make power of 2, keep dividing
    ll n;
    cin >> n;
    vector<ll> ans{n};
    for (ll bit = 0; bit < 30; ++bit) {
        if ((n >> bit) & 1) {
            if (n == (1 << bit)) break;
            n -= (1 << bit);
            ans.push_back(n);
        }
    }
    while (n > 0) {
        n /= 2;
        if (n > 0) ans.push_back(n);
    }

    cout << ans.size() << '\n';
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
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
