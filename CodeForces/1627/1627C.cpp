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
    vector<ll> deg(n, 0);
    vector<array<ll, 2>> edges(n - 1);
    map<pair<ll, ll>, ll> color;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
        g[u].push_back(v), g[v].push_back(u);
        ++deg[v], ++deg[u];
    }
    if (*max_element(all(deg)) > 2) return void(cout << "-1\n");
    // always in the form of a line
    vector<ll> ans(n - 1);
    queue<ll> bfs;
    vector<bool> vis(n, false);
    ll start = find(all(deg), 1) - deg.begin();  // start with degree 1
    bfs.push(start);
    vis[start] = true;
    ll col = 0;
    while (!bfs.empty()) {
        ll parent = bfs.front();
        bfs.pop();
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            color[{parent, child}] = col;
            col ^= 1;
            bfs.push(child);
            vis[child] = true;
        }
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll u = edges[i][0], v = edges[i][1];
        if (!color.count({u, v})) swap(u, v);
        ans[i] = color[{u, v}] + 2;  // 2 and 3, sum = 5
    }
    for (ll &A : ans) cout << A << ' ';
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