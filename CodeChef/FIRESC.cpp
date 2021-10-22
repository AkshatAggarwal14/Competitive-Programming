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
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    ll cnt = 0;
    vector<ll> vis(n, 0), components;

    auto dfs = [&](const auto &self, ll parent) -> void {
        vis[parent] = 1;
        cnt++;
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };

    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        cnt = 0;
        dfs(dfs, i);
        if (cnt) components.push_back(cnt);
    }

    ll p = 1, N = sz(components);
    for (ll i = 0; i < N; ++i) p = (p * components[i]) % MOD;
    cout << N << ' ' << p << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}