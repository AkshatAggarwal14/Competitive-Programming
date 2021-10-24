// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> val(n + 1);
    for (ll i = 1; i <= n; ++i) cin >> val[i];
    vector<vector<ll>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    ll u, v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0, mini = LLONG_MAX;
    function<void(ll)> dfs = [&](ll parent) {
        vis[parent] = true;
        mini = min(mini, val[parent]);
        for (auto child : adj[parent])
            if (!vis[child]) dfs(child);
    };
    for (ll i = 1; i <= n; ++i) {
        mini = LLONG_MAX;
        if (!vis[i]) dfs(i);
        if (mini != LLONG_MAX) ans += mini;
    }
    cout << ans << '\n';
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