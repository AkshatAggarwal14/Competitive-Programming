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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n, 0);
    // 0 -> not yet visited
    // 1 -> currently visiting
    // 2 -> already visited
    vector<int> curr;
    function<void(int, int)> dfs = [&](int node, int par) {
        curr.push_back(node);
        vis[node] = 1;
        for (int &child : g[node]) {
            if (child == par) continue;
            if (vis[child] == 2) continue;
            if (vis[child] == 0) dfs(child, node);
            if (vis[child] == 1) {
                vector<int> ans;
                ans.push_back(child);
                while (!curr.empty() && curr.back() != child) {
                    ans.push_back(curr.back());
                    curr.pop_back();
                }
                ans.push_back(child);
                cout << sz(ans) << '\n';
                for (int &i : ans) cout << i + 1 << ' ';
                cout << '\n';
                exit(0);
            }
        }
        curr.pop_back();
        vis[node] = 2;
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    cout << "IMPOSSIBLE";
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
