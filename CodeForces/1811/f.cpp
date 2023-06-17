#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

// dfs on degree 2 cycles
void dfs(int node, vector<vector<int>> &g, vector<bool> &vis, int &nodes, int &edges) {
    vis[node] = true;
    nodes++;
    for (auto ele : g[node]) {
        if (g[node].size() == 4 && g[ele].size() == 4) continue;
        if (ele > node) edges++;  // to count once
        if (vis[ele]) continue;
        dfs(ele, g, vis, nodes, edges);
    }
}

// dfs on degree 4 cycle
void dfs2(int node, vector<vector<int>> &g, vector<bool> &vis, int &nodes, int &edges) {
    vis[node] = 1;
    nodes++;
    for (auto ele : g[node]) {
        if (g[node].size() != 4 || g[ele].size() != 4) continue;
        if (ele > node) edges++;
        if (vis[ele]) continue;
        dfs2(ele, g, vis, nodes, edges);
    }
}

void test() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k = 0, twos = 0;
    vector<int> node4;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 2) {
            ++twos;
        } else if (g[i].size() == 4) {
            node4.push_back(i);
            ++k;
        } else {
            cout << "NO\n";
            return;
        }
    }

    // k nodes of degree 4
    // k * (k - 1) nodes of degree 2
    // total k * k
    // k + 1 cycles with k edges each
    if (k * k != n || m != k * (k + 1) || twos != k * (k - 1)) {
        cout << "NO\n";
        return;
    }

    vector<bool> vis(n, false);
    for (auto &node : node4) {
        int nodes = 0, edges = 0;
        dfs(node, g, vis, nodes, edges);
        if (nodes != k || edges != k) {
            cout << "NO\n";
            return;
        }
    }

    fill(vis.begin(), vis.end(), false);
    int nodes = 0, edges = 0;
    dfs2(node4[0], g, vis, nodes, edges);
    if (nodes != k || edges != k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
