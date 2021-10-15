#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const ll inf = LLONG_MAX;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);  // {node, weight}
    vector<ll> d(n, inf);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});  // ONE WAY FLIGHT
    }
    d[0] = 0;
    set<pair<ll, ll>> s;  //{distance, node}
    s.insert({0, 0});
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
    for (ll i = 0; i < n; ++i) cout << d[i] << ' ';
    return 0;
}
