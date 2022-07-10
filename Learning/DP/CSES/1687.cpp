// find node's kth ancestor -> boss k levels higher

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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // Brute: O(NQ) -> store parents and move up N times
    // boss[node, k] -> boss[par[node], k - 1] .... boss[par[par[par[...]]], 0] OR reach end and answer is -1

    /*
        Binary lifting:
        1. For every node maintain following
            - Parent of this node (up[u][1])
            - up(u, 2)
            - up(u, 4)
            - ...
            - up(u, 2^i) -> stored in up[u][i]
        2. To answer a query (u, k):
            - Represent k in binary format, k = (010110)_2 = 2^4 + 2^2 + 2^1
            - Jump 2^4 levels up, then jump 2^2, then jump 2^1 <- uses MSB
            - As there can be atmost log(n) jumps complexity is O(log(n)).
            - up[  up[  up[u][4]  ][2]  ][1]

        ? How to evaluate up[u][i]
        ? If we want to calc up[u][x] and we already know up[u][x - 1] and we have evaluated up table for up[u][x - 1]
        ? up[u][x] = up[up[u][x - 1]][x - 1], as 2 jumps of 2 ^ (x - 1) give one jump of 2 ^ x
        1. up[root][x] = 1
        2. up[u][0] = par[u]
        3. up[u][1] = up[up[u][0]][0]


        ? as there are N u's and log(N) x's, we can calculate all up tables in Nlog2(N) space and time
     */

    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    int LG = __lg(n);
    vector<vector<int>> up(n, vector<int>(LG, -1));
    int root = 0;
    function<void(int, int)> dfs = [&](int node, int par) {
        up[node][0] = par;
        for (int i = 1; i <= LG; ++i) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            }
        }
        for (auto &child : g[node]) {
            if (child == par) continue;
            dfs(child, node);
        }
    };
    dfs(root, -1);
    function<int(int, int)> query = [&](int u, int high) {
        if (u == -1 || high == 0) return u;
        int MSB = __lg(high);
        return query(up[u][MSB], high - (1 << (MSB)));
    };
    while (q--) {
        int u, k;
        cin >> u >> k, --u;
        int ans = query(u, k);
        if (ans != -1) ++ans;
        cout << ans << '\n';
    }
    return 0;
}
