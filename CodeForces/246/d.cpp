#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> color(n);
    for (ll i = 0; i < n; ++i) cin >> color[i];
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll maxC = *ranges::max_element(color);
    ll ans = maxC;  // let ans be some color
    vector<set<ll>> cardinality(maxC + 1);
    for (ll i = 0; i < n; ++i) {
        for (ll &child : g[i])
            if (color[child] != color[i])
                cardinality[color[i]].insert(color[child]);
        if ((sz(cardinality[color[i]]) > sz(cardinality[ans])) ||
            (sz(cardinality[color[i]]) == sz(cardinality[ans]) && color[i] < ans))
            ans = color[i];
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
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}