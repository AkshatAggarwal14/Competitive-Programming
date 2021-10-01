#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> vis(n + 1, -1);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<ll> bfs;
    bool flag = false;
    bfs.emplace(1);
    vis[1] = 0;
    while (!bfs.empty()) {
        ll parent = bfs.front();
        if (parent == n) {
            flag = true;
            break;
        }
        bfs.pop();
        for (auto child : adj[parent]) {
            if (vis[child] == -1) {
                vis[child] = parent;
                bfs.emplace(child);
            }
        }
    }

    if (!flag)
        cout << "IMPOSSIBLE";
    else {
        vector<ll> ans;
        ll x = n;
        while (x != 1) {
            ans.push_back(x);
            x = vis[x];
        }
        ans.push_back(1);
        ll X = ans.size();
        cout << X << '\n';
        reverse(ans.begin(), ans.end());
        for (auto ver : ans) cout << ver << ' ';
    }
}