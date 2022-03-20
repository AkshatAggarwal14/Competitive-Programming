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

void test() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1, u; i < n; ++i) {
        cin >> u, --u;
        g[u].push_back(i);
    }
    vector<int> subtree(n, 0);
    auto dfs = [&](const auto &self, int node) -> int {
        subtree[node] = 0;
        for (auto &child : g[node]) {
            subtree[node] += self(self, child) + 1;
        }
        return subtree[node];
    };
    dfs(dfs, 0);
    for (auto &x : subtree) cout << x << ' ';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
