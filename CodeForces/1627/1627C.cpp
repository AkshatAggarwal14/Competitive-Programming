#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    vector<pair<ll, ll>> edges(n - 1);
    map<pair<ll, ll>, ll> edge_color;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = minmax(u, v);
        g[u].push_back(v), g[v].push_back(u);
    }

    ll leaf = -1;  // always in the form of a line
    for (ll i = 0; i < n; i++) {
        if (sz(g[i]) > 2) return void(cout << -1 << '\n');
        if (sz(g[i]) == 1) leaf = i;
    }
    queue<ll> bfs;
    vector<bool> vis(n, false);
    vis[leaf] = true;
    bfs.push(leaf);
    ll col = 0;
    while (!bfs.empty()) {
        ll parent = bfs.front();
        bfs.pop();
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            edge_color[minmax(parent, child)] = col;
            col ^= 1;
            bfs.push(child);
            vis[child] = true;
        }
    }

    // 2 and 3, sum = 5
    for (ll i = 0; i < n - 1; ++i)
        cout << edge_color[edges[i]] + 2 << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}