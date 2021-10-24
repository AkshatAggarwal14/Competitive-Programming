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

void Solution() {
    //! number of connected components from graph of index to characters
    // 'a' --> n
    // 'b' --> n + 1

    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 26);  // 26 for the characters
    vector<ll> vis(n + 26, 0);

    string s;
    for (ll i = 0; i < n; ++i) {
        cin >> s;
        for (char &c : s) {
            g[i].push_back(n + c - 'a');
            g[n + c - 'a'].push_back(i);
        }
    }
    auto dfs = [&](const auto &self, ll parent) -> void {
        vis[parent] = 1;
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };
    ll components = 0;
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        dfs(dfs, i);
        components++;
    }

    cout << components << '\n';
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