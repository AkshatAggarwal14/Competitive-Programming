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
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

ll query(ll a, ll b) {
    cout << "? " << a << ' ' << b << endl;
    ll ans;
    cin >> ans;
    assert(ans != 0);
    return ans;
}

void test() {
    ll ans = 0;
    for (ll i = 1; i <= 5; ++i) {
        for (ll j = i + 1; j <= i + 5; ++j) {
            ll val1 = query(i, j);
            ll val2 = query(j, i);
            if (val1 == -1) {
                cout << "! " << j - 1 << endl;
                return;
            }
            if (val1 != val2) {
                cout << "! " << val1 + val2 << endl;
                return;
            }
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
