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
    ll n, k;
    cin >> n >> k;

    auto query = [&](ll i) -> ll {
        cout << "? " << i + 1 << endl;
        ll x;
        cin >> x;
        return x;
    };

    vector<bool> toQuery(n, false);
    ll i = 0, res = 0;
    while (i + k - 1 < n) {
        res ^= query(i);
        i += k;
    }

    i -= k;
    ++i;
    while (i + k - 1 < n) {
        res ^= query(i);
        ++i;
    }

    cout << "! " << res << endl;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
