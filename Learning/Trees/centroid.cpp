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
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto get_centroid = [&](int node, int par = -1) {
        int maxi = INT_MAX, centroid = -1;
        auto dfs = [&](const auto &self, int _n, int p = -1) -> int {
            int sum = 1;
            int max_subtree = 0;
            for (auto &child : g[_n]) {
                if (child == p) continue;
                int val = self(self, child, _n);
                max_subtree = max(max_subtree, val);
                sum += val;
            }
            int up = n - sum;
            max_subtree = max(max_subtree, up);
            if (max_subtree < maxi) {
                maxi = max_subtree;
                centroid = _n;
            }
            return sum;
        };
        dfs(dfs, node, par);
        return centroid + 1;
    };
    cout << get_centroid(0, -1) << '\n';
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
*/