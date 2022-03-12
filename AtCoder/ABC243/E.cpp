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
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    vector<vector<pair<ll, ll>>> g(n);
    vector<array<ll, 3>> edges(m);
    for (ll i = 0, u, v, wt; i < m; ++i) {
        cin >> u >> v >> wt, --u, --v;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
        edges[i] = {u, v, wt};
        d[u][v] = wt;
        d[v][u] = wt;
    }
    for (ll i = 0; i < n; ++i) d[i][i] = 0;
    // floyd warshall to calculate the distances
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll cnt = 0;
    for (auto &[u, v, wt] : edges) {
        // check if distance remain same, without u -> v
        ll mini = INF;
        for (auto &[other_v, other_wt] : g[u]) {
            if (other_v != v) {
                mini = min(mini, d[u][other_v] + d[other_v][v]);
            }
        }
        if (mini == d[u][v]) ++cnt;
    }
    cout << cnt << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cout.rdbuf(cout.rdbuf()), std::cin.rdbuf(cin.rdbuf());
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
