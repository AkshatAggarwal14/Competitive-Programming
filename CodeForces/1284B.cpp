#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n;
    cin >> n;
    vector<ll> mn(n), mx, done(n);
    for (int i = 0; i < n; ++i) {
        ll l;
        cin >> l;
        vector<ll> s(l);
        for (ll j = 0; j < l; ++j) cin >> s[j];
        for (ll j = 1; j < l; ++j)
            if (s[j] > s[j - 1]) done[i] = 1;  // will always contribute +n
        mn[i] = *ranges::min_element(s);
        if (done[i]) continue;
        mx.push_back(*ranges::max_element(s));
    }
    ranges::sort(mx);
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        if (done[i]) {
            res += n;
        } else {
            ll up = upper_bound(mx.begin(), mx.end(), mn[i]) - mx.begin();
            res += n - up;
        }
    }
    cout << res << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}