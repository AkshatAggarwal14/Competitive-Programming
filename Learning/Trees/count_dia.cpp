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
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    queue<int> bfs;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 1 || deg[i] == 0) {  // 0 handles root being only node
            bfs.push(i);
            deg[i] = 0;
        }
    int count = int(bfs.size());
    queue<int> n_bfs;
    while (count < n) {
        while (!bfs.empty()) {
            int node = bfs.front();
            bfs.pop();
            for (auto &child : g[node]) {
                --deg[child];
                if (deg[child] == 1) n_bfs.push(child);
            }
        }
        count += int(n_bfs.size());
        swap(bfs, n_bfs);
    }
    vector<int> centers;
    while (!bfs.empty())
        centers.push_back(bfs.front()), bfs.pop();

    auto get_max_dist = [&](int node, int par = -1) {
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int n_, int p, int dist) {
            ans = max(ans, dist);
            for (auto &child : g[n_]) {
                if (child == p) continue;
                dfs(child, n_, dist + 1);
            }
        };
        dfs(node, par, 0);
        return ans;
    };

    auto get_count = [&](int dist, int node, int par = -1) {
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int n_, int p, int d) {
            ans += (d == dist);  // check leaf
            for (auto &child : g[n_]) {
                if (child == p) continue;
                dfs(child, n_, d + 1);
            }
        };
        dfs(node, par, 0);
        return ans;
    };

    int ans = 0;
    if (centers.size() == 1) {
        // need number of nodes at distance diameter / 2 in each subtree
        int dia = 0;
        for (auto &child : g[centers[0]])
            dia = max(dia, get_max_dist(child, centers[0]));
        // dia value is now diameter / 2
        vector<int> sz;
        for (auto &child : g[centers[0]])
            sz.push_back(get_count(dia, child, centers[0]));
        int cursum = 0;
        for (int i = 0; i < int(sz.size()); ++i) {
            ans += cursum * sz[i];
            cursum += sz[i];
        }
    } else {
        int max1 = get_max_dist(centers[0], centers[1]);
        int cmax1 = get_count(max1, centers[0], centers[1]);
        int max2 = get_max_dist(centers[1], centers[0]);
        int cmax2 = get_count(max2, centers[1], centers[0]);
        ans = cmax1 * cmax2;
    }
    cout << ans << '\n';
    return 0;
}

/*
1 center:
3
1 2
2 3

2 center:
4
1 2
2 3
3 4
*/