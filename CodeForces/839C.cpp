#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
using ld = long double;
auto sz = [](const auto& container) -> ll { return container.size(); };

void Solution() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](const auto& self, ll vertex = 0, ll parent = -1) -> ld {
        ld sum = 0;
        for (auto child : g[vertex])
            if (child != parent)
                sum += self(self, child, vertex) + 1;  // 1 for moving 1 step
        // -1 for all paths back to previous, except at root
        return (sum ? sum / (sz(g[vertex]) - (parent != -1)) : 0);
    };
    cout << dfs(dfs);
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