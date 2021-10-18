// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> color(n + 1, 0);
    vector<ll> sz(n + 1, 0);
    vector<ll> temp;
    for (ll i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        temp.resize(k);
        for (ll j = 0; j < k; ++j)
            cin >> temp[j];

        // For k numbers make edges between adjacent <- to reduce number of edge
        for (ll j = 1; j < k; ++j) {
            if (temp[j] != temp[j - 1]) {
                adj[temp[j]].push_back(temp[j - 1]);
                adj[temp[j - 1]].push_back(temp[j]);
            }
        }
        temp.clear();
    }
    ll component_no = 0;
    function<ll(ll)> dfs = [&](ll parent) {
        if (color[parent]) return 0LL;
        color[parent] = component_no;  // color = component index
        ll ans = 1;                    // so every child adds 1 too
        for (auto child : adj[parent]) ans += dfs(child);
        return ans;
    };

    for (ll i = 1; i <= n; ++i) {
        if (!color[i]) {
            component_no++;
            sz[component_no] = dfs(i);  // size of a component is given by dfs
        }
    }
    for (ll i = 1; i <= n; ++i)
        cout << sz[color[i]] << ' ';  // size of color
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