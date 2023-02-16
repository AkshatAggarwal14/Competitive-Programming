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

const ll INF = 1e9;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> d(n, vector<int>(n, INF));
    vector<int> col(n);
    for (auto &x : col) cin >> x;

    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<array<int, 2>> bfs;
    bfs.push({0, n - 1});  // {taka, aoki, steps}
    d[0][n - 1] = 0;
    while (!bfs.empty()) {
        auto [taka_pos, aoki_pos] = bfs.front();
        bfs.pop();
        for (auto &&i : g[taka_pos])
            for (auto &&j : g[aoki_pos])
                if (col[i] != col[j] && d[i][j] == INF) {
                    bfs.push({i, j});
                    d[i][j] = 1 + d[taka_pos][aoki_pos];
                }
    }
    cout << (d[n - 1][0] == INF ? -1 : d[n - 1][0]) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
