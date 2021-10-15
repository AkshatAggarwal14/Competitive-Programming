#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const ll inf = 1e18;

//! Floyd–Warshall algorithm
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, q, u, v, w, a, b;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min(w, dist[u][v]), dist[v][u] = min(w, dist[v][u]);
    }

    for (ll i = 0; i < n; i++) dist[i][i] = 0;

    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--) {
        cin >> a >> b;
        a--, b--;
        cout << (dist[a][b] == inf ? -1 : dist[a][b]) << '\n';
    }
    return 0;
}

// TLE
int dijsktra() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, q, u, v, w, a, b;
    cin >> n >> m >> q;
    vector<vector<pair<ll, ll>>> adj(n);  // {node, weight}
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    //! Dijsktra TLEd because mlogn and m <= n^2
    // Thus overall n^3*log(n)
    auto dijkstra = [&](ll id) {
        vector<ll> d(n, inf);
        d[id] = 0;
        set<pair<ll, ll>> s;  //{distance, node}
        s.insert({0, id});
        while (!s.empty()) {
            ll dis = s.begin()->first;
            ll vertex = s.begin()->second;
            s.erase(s.begin());
            for (pair<ll, ll>& x : adj[vertex]) {
                ll new_d = dis + x.second;
                ll new_v = x.first;
                if (new_d < d[new_v]) {
                    s.erase({d[new_v], new_v});
                    d[new_v] = new_d;
                    s.insert({d[new_v], new_v});
                }
            }
        }
        for (ll i = 0; i < n; ++i)
            if (d[i] == inf) d[i] = -1;
        return d;
    };
    vector<vector<ll>> D(n);
    for (ll i = 0; i < n; ++i) D[i] = dijkstra(i);
    while (q--) {
        cin >> a >> b;
        a--, b--;
        cout << D[a][b] << '\n';
    }
    return 0;
}
