#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

int32_t main() {
    int n;
    cin >> n;
    vector<set<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    // vis[i] = true if we have chosen i as the centroid of some
    // component, equivalent to the fact that these vertices are not in
    // remaining components and also block off the components from each
    // other
    vector<int> vis(n);
    // par[i] = parent of i in the centroid tree
    vector<int> par(n);
    vector<int> sub(n);
    // blocked vertex => size = 0
    auto dfs_subtree = [&](const auto& self, int node, int p) -> int {
        if (vis[node]) return 0;
        sub[node] = 1;
        for (auto& child : g[node])
            if (child != p) sub[node] += self(self, child, node);
        return sub[node];
    };

    auto dfs_centroid = [&](const auto& self, int node, int p, int limit) -> int {
        for (auto& child : g[node])
            if (child != p && !vis[child] && sub[child] > limit)
                return self(self, child, node, limit);
        return node;
    };

    // p -> parent in the centroid tree
    auto dfs_create = [&](const auto& self, int node, int p) -> void {
        dfs_subtree(dfs_subtree, node, -1);
        int centroid = dfs_centroid(dfs_centroid, node, -1, sub[node] / 2);
        vis[centroid] = 1;
        par[centroid] = p;
        for (auto v : g[centroid])
            if (!vis[v]) self(self, v, centroid);
    };

    dfs_create(dfs_create, 0, -1);
    dbg(par);

    return 0;
}

/*
1 centroid:
9
2 1
2 3
2 4
2 5
2 6
2 7
7 8
8 9

16
1 4
2 4
3 4
4 5
5 6
6 7
7 8
7 9
6 10
10 11
11 12
11 13
12 14
13 15
13 16
*/