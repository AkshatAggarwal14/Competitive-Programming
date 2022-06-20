/**
 *    author:  master._.mind
 *    created: 2022.06.21 00:19:35
 **/

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
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    auto solve_for = [&](ll mx) {
        ll c1 = 0, c2 = 0;
        for (ll i = 0; i < n; ++i) {
            ll diff = mx - a[i];
            c2 += diff / 2;
            c1 += diff % 2;
        }
        ll L = 1, R = c2 - c1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            // Minimum count of 2 + 1 >= count of 1
            if (c2 - M + 1 >= c1 + 2 * M) {
                L = M;
            } else {
                R = M;
            }
        }
        c2 -= L;
        c1 += 2 * L;
        if (c1 > c2) return 2 * c1 - 1;
        return 2 * c2;
    };
    ll maxi = *max_element(all(a));
    // >= maxi + 2 dont make sense as maxi + 2 is just maxi with +2 for each element
    cout << min(solve_for(maxi), solve_for(maxi + 1)) << '\n';
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
