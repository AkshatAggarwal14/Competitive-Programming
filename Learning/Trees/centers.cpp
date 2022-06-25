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
    for (auto &c : centers) cout << c + 1 << ' ';
    cout << '\n';
    return 0;
}

// can also be calculated by finding nodes with minimum remoteness value -> max(dist(node, endpoint1), dist(node, endpoint2))

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