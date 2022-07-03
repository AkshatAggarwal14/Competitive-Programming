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