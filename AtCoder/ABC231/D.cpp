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

bool flag = true;
struct graph {
    vector<vector<ll>> adj;
    vector<ll> d;
    vector<ll> deg;
    ll n;
    graph(ll &vertices) { n = std::forward<ll>(vertices), adj.resize(n), d.resize(n, -1), deg.resize(n, 0); }
    void read(ll edges) {
        set<pair<ll, ll>> st;
        for (ll i = 0; i < edges; ++i) {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            if (st.count({u, v})) continue;
            ++deg[u], ++deg[v];
            st.insert({u, v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void dfs(ll node, ll parent) {
        d[node] = 1;
        for (ll &child : adj[node]) {
            if (d[child] != -1) {
                if (child != parent) flag = false;  //! CYCLE
                continue;
            }
            d[child] = 1;
            dfs(child, node);
        }
    }
};

// deg > 2 or cycle
void Solution() {
    ll n, m;
    cin >> n >> m;
    graph g(n);
    g.read(m);
    ll mx = *max_element(all(g.deg));
    if (mx > 2) flag = false;
    for (ll i = 0; i < n; ++i) {
        if (g.d[i] != -1) continue;
        g.dfs(i, -1);
    }
    cout << (flag ? "Yes" : "No");
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
    return 0;
}