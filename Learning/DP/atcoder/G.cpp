#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int> dp(n + 1, -1);

    // dfs = longestPath starting at source
    function<int(int)> dfs = [&](int source) {
        int &ans = dp[source];
        if (ans != -1) return ans;

        int longest = 0, mx = 0;
        for (auto &child : g[source]) {
            mx = max(mx, 1 + dfs(child));
        }
        return ans = longest + mx;
    };

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dfs(i));
    cout << ans << '\n';

    return 0;
}
