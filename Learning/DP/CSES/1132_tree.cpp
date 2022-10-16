#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> mDepth(n);  // max depth to leaf
    function<void(int, int)> preprocess = [&](int node, int par) {
        int mx = -1;
        for (auto &child : g[node]) {
            if (child == par) continue;
            preprocess(child, node);
            mx = max(mx, mDepth[child]);
        }
        mDepth[node] = 1 + mx;
    };

    preprocess(0, -1);
    vector<int> ans(n);
    ans[0] = mDepth[0];

    function<void(int, int, int)> dfs = [&](int node, int par, int partial_ans) {
        vector<int> depths;
        for (auto &child : g[node]) {
            if (child == par) continue;
            depths.push_back(mDepth[child]);
        }
        int sz = int(depths.size());
        vector<int> suffMax(sz + 1), prefMax(sz + 1);
        for (int i = 0; i < sz; ++i) prefMax[i + 1] = max(prefMax[i], depths[i]);
        for (int i = sz - 1; i >= 0; --i) suffMax[i] = max(suffMax[i + 1], depths[i]);
        auto get_without = [&](int id) { return max(prefMax[id], suffMax[id + 1]); };

        int i = 0;
        for (auto &child : g[node]) {
            if (child == par) continue;

            int new_partial = 1 + max(get_without(i), partial_ans);
            ans[child] = max(1 + new_partial, mDepth[child]);
            dfs(child, node, new_partial);

            ++i;
        }
    };

    dfs(0, -1, 0);
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
}
