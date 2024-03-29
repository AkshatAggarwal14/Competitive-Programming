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
    vector<ll> vals;
    for (ll i = 1; i <= 15; ++i) {
        ll times = i, p = 1;
        while (times--) {
            p *= i;
        }
        vals.push_back(p);
    }
    ll n;
    cin >> n;
    auto it = find(vals.begin(), vals.end(), n);
    if (it == vals.end()) {
        cout << "-1\n";
    } else {
        cout << (it - vals.begin() + 1) << '\n';
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
