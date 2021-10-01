#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> adj;
vector<bool> vis;

void dfs(ll parent) {
    vis[parent] = true;
    for (auto child : adj[parent]) {
        if (vis[child]) continue;
        dfs(child);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> parents;
    for (ll i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        dfs(i);
        parents.push_back(i);
    }

    ll sz = parents.size();
    cout << sz - 1 << '\n';
    for (ll i = 1; i < sz; ++i) {
        cout << parents[i - 1] << ' ' << parents[i] << '\n';
    }
}