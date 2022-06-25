#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

template <typename T>
struct RMQ {
    int n, levels;
    vector<T> values;
    vector<vector<int>> range_low;

    int min_index(int a, int b) const { return values[b] < values[a] ? b : a; }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        build();
    }

    void build() {
        levels = 32 - __builtin_clz(n);
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = min_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    int rmq_index(int a, int b) const {
        assert(a < b);
        int level = 31 - __builtin_clz(b - a);
        return min_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    int rmq_value(int a, int b) const { return values[rmq_index(a, b)]; }
};

struct LCA {
    int n;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<int> euler;
    vector<int> first_occurrence;
    RMQ<int> rmq;

    LCA(int _n = 0) : n(_n), adj(n), depth(n), first_occurrence(n) {}

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int node, int parent = -1) {
        depth[node] = ((parent == -1) ? 0 : depth[parent] + 1);
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);

        for (int neighbor : adj[node])
            if (neighbor != parent) {
                dfs(neighbor, node);
                euler.push_back(node);
            }
    }

    void build(int root = 0) {
        dfs(root);
        assert((int)euler.size() == 2 * n - 1);
        vector<int> euler_depths;
        for (int node : euler)
            euler_depths.push_back(depth[node]);
        rmq.build(euler_depths);
    }

    int lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];
        if (a > b) swap(a, b);
        return euler[rmq.rmq_index(a, b + 1)];
    }

    int dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }
};

int32_t main() {
    int n;
    cin >> n;
    LCA lca(n);
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        lca.add_edge(u, v);
    }
    lca.build(0);
    return 0;
}

/*
7
1 2
2 3
2 4
2 5
5 6
5 7
*/
