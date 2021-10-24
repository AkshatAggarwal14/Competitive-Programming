// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n;  //vertices
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> color(n + 1);
    vector<bool> vis(n + 1, false);
    ll num;
    for (ll i = 2; i <= n; ++i) {
        cin >> num;
        adj[i].push_back(num);
        adj[num].push_back(i);
    }
    // dbg(adj);
    for (ll i = 1; i <= n; ++i) cin >> color[i];

    function<void(ll)> dfs = [&](ll parent) -> void {
        vis[parent] = true;
        for (auto child : adj[parent]) {
            // only do DFS if child is of same color
            if (!vis[child] && color[child] == color[parent])
                dfs(child);
        }
    };

    ll components = 0;
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << '\n';
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