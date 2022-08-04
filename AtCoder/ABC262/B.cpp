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
    ll n, m;
    cin >> n >> m;
    vector<vector<bool>> mat(n, vector<bool>(n));
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        mat[u][v] = mat[v][u] = true;
    }
    ll ans = 0;
    for (ll u = 0; u < n; ++u) {
        for (ll v = u + 1; v < n; ++v) {
            for (ll w = v + 1; w < n; ++w) {
                if (mat[v][u] && mat[v][w] && mat[u][w]) {
                    ++ans;
                }
            }
        }
    }
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
