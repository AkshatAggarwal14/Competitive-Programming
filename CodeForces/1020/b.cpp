// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, num;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        adj[i + 1].push_back(num);
    }
    vector<ll> ans;
    vector<ll> vis;
    function<void(ll)> dfs = [&](ll parent) {
        if (vis[parent]) {
            ans.push_back(parent);
            return;
        }
        vis[parent] = 1;
        for (ll &child : adj[parent]) dfs(child);
    };
    for (ll i = 1; i <= n; ++i) {
        vis.assign(n + 1, 0);  // restarting dfs
        dfs(i);
    }
    for (ll i = 0; i < n; ++i) cout << ans[i] << ' ';
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