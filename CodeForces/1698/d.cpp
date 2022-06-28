#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    auto ask = [&](ll l, ll r) {
        cout << "? " << l + 1 << ' ' << r + 1 << endl;
        ll cnt = 0;
        ll num;
        for (ll i = l; i <= r; ++i) {
            cin >> num;
            if (num <= r + 1 && num >= l + 1) ++cnt;
        }
        return cnt;
    };

    ll l = 0, r = n - 1;
    while (r > l) {
        ll m = (l + r) / 2;
        if (ask(l, m) % 2) {  // query gives odd num for suitable subarray
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << l + 1 << endl;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
