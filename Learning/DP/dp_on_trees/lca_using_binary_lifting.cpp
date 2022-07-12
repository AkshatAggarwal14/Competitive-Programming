#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    int LG = __lg(n);
    vector<vector<int>> up(n, vector<int>(LG, -1));
    vector<int> in_timer(n), out_timer(n);
    int root = 0, time = 0;
    function<void(int, int)> dfs = [&](int node, int par) {
        up[node][0] = par;
        for (int i = 1; i < LG; ++i) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            }
        }

        in_timer[node] = ++time;
        for (auto &child : g[node]) {
            if (child == par) continue;
            dfs(child, node);
        }
        out_timer[node] = ++time;
    };

    auto is_ancestor = [&](int u, int v) {
        return in_timer[u] <= in_timer[v] && out_timer[v] <= out_timer[u];
    };

    auto lca = [&](int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = LG - 1; i >= 0; --i) {
            // when we are in the subtree of LCA on u's side, any node is not ancestor, so we find largest 2^x where up[u][x] is not ancestor and go up, then repeat
            if (up[u][i] != -1 && !is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        // At this point we are on a child of LCA
        return up[u][0];
    };

    dfs(root, -1);

    while (q--) {
        int a, b;
        cin >> a >> b, --a, --b;
        cout << lca(a, b) + 1 << '\n';
    }

    return 0;
}
