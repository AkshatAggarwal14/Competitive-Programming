#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

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
                range_low[k][i] = min_index(
                    range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    int rmq_index(int a, int b) const {
        assert(a < b);
        int level = 31 - __builtin_clz(b - a);
        return min_index(range_low[level][a],
                         range_low[level][b - (1 << level)]);
    }

    int rmq_value(int a, int b) const { return values[rmq_index(a, b)]; }
};

struct LCA {
    int n;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end;
    RMQ<int> rmq;

    LCA(int _n = 0) : n(_n), adj(n), depth(n), first_occurrence(n), tour_start(n), tour_end(n) {}

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int tour;
    void dfs(int node, int parent = -1) {
        depth[node] = ((parent == -1) ? 0 : depth[parent] + 1);
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_start[node] = tour++;

        for (int neighbor : adj[node])
            if (neighbor != parent) {
                dfs(neighbor, node);
                euler.push_back(node);
            }
        tour_end[node] = tour;
    }

    void build(int root = 0) {
        dfs(root);
        assert((int)euler.size() == 2 * n - 1);
        vector<int> euler_depths;
        for (int node : euler)
            euler_depths.push_back(depth[node]);
        rmq.build(euler_depths);
    }

    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];
        if (a > b) swap(a, b);
        return euler[rmq.rmq_index(a, b + 1)];
    }

    int dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }
};

void test() {
    int n;
    cin >> n;
    LCA lca(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        lca.add_edge(u, v);
    }
    lca.build();
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        vector<int> p(m);

        for (auto &v : p) {
            cin >> v;
            v--;
        }

        int anc = p.front();

        for (auto &v : p)
            anc = lca.get_lca(anc, v);  // lca of all nodes in path

        int start = anc, end = anc;
        bool success = true;

        for (auto &v : p) {
            if (lca.on_path(v, start, end))  // if v lies on path from s to e
                continue;

            if (lca.on_path(start, v, anc)) {  // if start lies on path from lca of all to v, then start is modified
                start = v;
                continue;
            }

            if (lca.on_path(end, v, anc)) {
                end = v;
                continue;
            }

            success = false;  // maybe start and end in different branches than v
        }

        success &= (lca.get_lca(start, end) == anc);
        cout << (success ? "YES" : "NO") << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
