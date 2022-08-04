#include <bits/stdc++.h>
// #include <Akshat.hpp>
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
    /* you have 2 options:
        1. either include and edge (node, child) -> divide into subtrees with other childs, and node deeper than child
        2. do not include an edge of form (node, _) -> divided into subtrees.

        dp[u][0]: max possible size of matching that i can select in subtree of u, when i dont select edge with end point = u
        dp[u][1]: do select edge with endpoint u

        dp[u][0]: Sum(dp[child][1])
        ? try for all edges, 1 means edge selected
        ? max across all children
        dp[u][1]: 1 + Ans(c1) + Ans(c2) + Ans(c3) +... + Ans(cK-1) + dp[ck][0] {as ck connected with parent}
    */
    vector<array<int, 2>> dp(n, {0, 0});
    function<void(int, int)> dfs = [&](int node, int par) {
        int sum = 0;
        for (auto &child : g[node]) {
            if (child == par) continue;
            dfs(child, node);
            sum += dp[child][1];
        }
        dp[node][0] = sum;
        for (auto &child : g[node]) {
            if (child == par) continue;
            dp[node][1] = max(dp[node][1], 1 + (sum - dp[child][1]) + dp[child][0]);
        }
    };
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}