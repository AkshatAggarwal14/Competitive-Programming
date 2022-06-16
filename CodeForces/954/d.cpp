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

/*
    d[s][t] = d[s][u] + d[u][v] + d[v][t]
    so to keep d[s][t] same, check if 1 + d[s][u] + d[t][v] is >= origial d[s][t]
    by iterating over all u, v,  d[u][v] = 1 as edge added
*/

void Solution() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t, --s, --t;
    vector<vector<ll>> g(n);
    vector<vector<bool>> junction(n, vector<bool>(n, false));
    while (m--) {
        ll u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v), g[v].push_back(u);
        junction[v][u] = junction[u][v] = true;
    }
    auto BFS = [&](ll source) -> vector<ll> {
        vector<ll> dist(n, -1);
        queue<ll> bfs({source});
        dist[source] = 0;
        while (!bfs.empty()) {
            ll node = bfs.front();
            bfs.pop();
            for (ll &child : g[node]) {
                if (dist[child] != -1) continue;
                dist[child] = dist[node] + 1;
                bfs.push(child);
            }
        }
        return dist;
    };
    ll pairs = 0;
    vector<ll> d_s(BFS(s)), d_t(BFS(t));
    for (ll u = 0; u < n - 1; ++u) {
        for (ll v = u + 1; v < n; ++v) {
            // d[u][v] = 1
            ll D = min(d_s[u] + d_t[v] + 1, d_s[v] + d_t[u] + 1);
            if (!junction[u][v] && D >= d_s[t]) pairs++;
        }
    }
    cout << pairs << '\n';
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