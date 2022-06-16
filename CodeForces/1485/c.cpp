#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto& container) -> ll { return container.size(); };

template <bool b>
auto binsearch(auto l, auto r, const auto& pred) {
    --l, ++r;
    for (decltype(l) m; m = midpoint(l, r), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}

// returns first i in [l, r], p(i) false, and if none found, returns r + 1
auto find_first_false(auto l, auto r, const auto& p) {
    return binsearch<false>(l, r, p);
}

// returns last i in [l, r], p(i) true, and if none found, returns l - 1
auto find_last_true(auto l, auto r, const auto& p) {
    return binsearch<true>(l, r, p);
}

/*
    We need numbers of the form kn+k
    (kn+k)/n = k
    (kn+k)%n = k

        x  -  n+1     2n+2    3n+3    .....kn+k (k=0,1,2..n-1)
    y
    ---------------------
    1           
    2          3
    3          4       8
    4          5       10      15
    5          6       12      18      24 ..<- [Y*Y-1]

*/

void Solution() {
    ll x, y;
    cin >> x >> y;
    ll full = min(ll(sqrt(x + 1)), y);  // until this y, we can use all values of x
    ll ans = (full * (full - 1)) / 2;   // count of all values until [full]
    ll max_x = min(x, y * y - 1);
    ll max_y = min(y, max_x - 1);
    vector<array<ll, 2>> vals;
    //  cnt = count of vals of x for a particular y, cnt cant be greater than sqrt(1e9) as thats max x for some y
    for (ll cnt = 1; cnt * cnt - 1 < 1000000000LL; ++cnt) {
        ll xx = find_last_true(2LL, max_y, [&](ll yy) -> bool { return (max_x / (yy + 1) >= cnt); });  // this finds last xx for given count
        if (xx <= cnt + 1) break;                                                                      // already counted in full
        vals.push_back({xx, cnt});
        // cout << xx << ' ' << cnt << '\n';
    }
    vals.push_back({full, full - 1});
    for (ll i = 0; i < sz(vals) - 1; ++i) {  // count of successive
        ans += (vals[i][0] - vals[i + 1][0]) * vals[i][1];
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}