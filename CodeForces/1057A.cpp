// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, p;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> path;
    for (ll i = 2; i <= n; ++i) {
        cin >> p;
        adj[p].push_back(i);
    }

    function<bool(ll)> dfs = [&](ll parent) {
        bool found = (parent == n);
        for (auto child : adj[parent]) found |= dfs(child);
        if (found) path.push_back(parent);
        return found;
    };

    dfs(1);
    reverse(path.begin(), path.end());
    for (auto& v : path) cout << v << " ";
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