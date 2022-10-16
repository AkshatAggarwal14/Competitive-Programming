#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> downPath(n);  // length of longest path from this node to leaf
    // 2 cases: 1. Either this node passes through diameter - 2 + two maximum downPath(child)
    //          2. Either the diameter is in a subtree, so take maximum with children
    function<int(int, int)> dfs = [&](int node, int par) {
        int mx = -1;
        vector<int> downs;
        for (auto &child : g[node]) {
            if (child == par) continue;
            mx = max(mx, dfs(child, node));
            downs.push_back(downPath[child]);
        }
        sort(downs.begin(), downs.end(), greater<int>());
        int sz = int(downs.size());
        if (sz == 0) {
            downPath[node] = 0;
            return 0;
        } else {
            downPath[node] = 1 + *max_element(downs.begin(), downs.end());
            if (sz == 1) {
                return max(mx, downPath[node]);
            } else {
                return max(mx, 2 + downs[0] + downs[1]);
            }
        }
    };
    cout << dfs(0, -1) << '\n';
}