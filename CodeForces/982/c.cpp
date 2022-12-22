#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
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
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n & 1) return void(cout << "-1\n");
    vector<int> sub(n);
    int ans = 0;
    function<void(int, int)> dfs = [&](int node, int par) {
        sub[node] = 1;
        for (auto &child : g[node]) {
            if (child != par) {
                dfs(child, node);
                sub[node] += sub[child];
            }
        }
        // count all subtrees with even size except entire tree
        if (sub[node] % 2 == 0 && node != 0) ++ans;
    };
    dfs(0, -1);
    cout << ans << '\n';
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
