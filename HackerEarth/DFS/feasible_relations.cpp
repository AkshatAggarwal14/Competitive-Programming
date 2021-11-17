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
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

void Solution() {
    ll n, m, u, v;
    string R;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> color(n, -1);  // -1 means unvisited
    vector<pair<ll, ll>> not_edges;
    ll curr_color = 1;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> R >> v;
        u--, v--;
        if (R == "=")
            g[u].push_back(v), g[v].push_back(u);
        else
            not_edges.push_back({u, v});
    }

    function<void(ll)> dfs = [&](ll parent) {
        color[parent] = curr_color;
        for (auto &child : g[parent]) {
            if (color[child] != -1) continue;
            dfs(child);
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (color[i] != -1) continue;
        dfs(i);
        ++curr_color;
    }
    for (auto &[x, y] : not_edges)
        if (color[x] == color[y])
            return void(cout << "NO\n");
    cout << "YES\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}