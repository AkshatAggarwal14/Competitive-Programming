#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

bool area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0);
}

void Solution() {
    ll n, ctr = 0;
    cin >> n;
    vector<pair<ll, ll>> vv(n);
    for (ll i = 0; i < n; ++i) cin >> vv[i].first >> vv[i].second;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            for (ll k = j + 1; k < n; ++k) {
                ll x1 = vv[i].first, y1 = vv[i].second;
                ll x2 = vv[j].first, y2 = vv[j].second;
                ll x3 = vv[k].first, y3 = vv[k].second;
                if (!area(x1, y1, x2, y2, x3, y3)) ctr++;
            }
        }
    }
    cout << ctr << '\n';
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