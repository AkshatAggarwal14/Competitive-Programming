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
    // recieved in sorted order, size[node] = 1 + size[subtree]
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> g(n);
    vector<bool> vis(n, false);
    vector<ll> subtree_sz(n, 0), idx_in_dfs(n, 0), dfs_order;
    for (ll i = 1, u; i < n; i++) {
        cin >> u, --u;
        g[i].push_back(u), g[u].push_back(i);
    }
    const auto dfs = [&](const auto &self, ll parent) -> void {
        vis[parent] = true;
        idx_in_dfs[parent] = sz(dfs_order);
        dfs_order.push_back(parent + 1);
        vector<ll> can_vis;
        for (const auto &child : g[parent])
            if (!vis[child]) can_vis.push_back(child);
        sort(all(can_vis));
        subtree_sz[parent]++;  // this node itself
        for (const auto &child : can_vis) {
            self(self, child);  // to calc subtree_sz[child]
            subtree_sz[parent] += subtree_sz[child];
        }
    };
    dfs(dfs, 0LL);
    ll ans = -1;
    while (q--) {
        ll ui, ki;
        cin >> ui >> ki, --ui, --ki;
        ans = (ki >= subtree_sz[ui]) ? -1 : dfs_order[idx_in_dfs[ui] + ki];
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}