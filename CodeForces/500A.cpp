#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
#define sz(x) ((ll)(x).size())

void Solution() {
    ll n, t, num;
    cin >> n >> t;
    vector<vector<ll>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (ll i = 1; i <= n - 1; ++i) {
        cin >> num;
        adj[i].push_back(i + num);
    }
    function<void(ll)> dfs = [&](ll parent) {
        vis[parent] = true;
        for (auto child : adj[parent])
            if (!vis[child]) dfs(child);
    };
    dfs(1);
    if (vis[t])
        cout << "YES";
    else
        cout << "NO";
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