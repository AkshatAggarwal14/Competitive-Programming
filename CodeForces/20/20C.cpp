#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
const ll inf = 1e18;

void Solution() {
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    vector<ll> dist(n, inf);
    vector<ll> pred(n, -1);  // predecessor
    dist[0] = 0;
    set<pair<ll, ll>> s = {{0, 0}};  // {distance, node}
    while (!s.empty()) {
        ll from = s.begin()->second;
        s.erase(s.begin());
        for (auto &child : adj[from]) {
            ll to = child.first;
            ll len = child.second;
            if (dist[to] > dist[from] + len) {
                s.erase({dist[to], to});
                dist[to] = dist[from] + len;
                pred[to] = from;
                s.insert({dist[to], to});
            }
        }
    }
    if (dist[n - 1] == inf) return void(cout << -1 << '\n');
    vector<ll> path;
    ll X = n - 1;
    while (X != -1) {
        path.push_back(X);
        X = pred[X];
    }
    reverse(path.begin(), path.end());
    for (auto &x : path) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}