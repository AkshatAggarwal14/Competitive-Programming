#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    deque<ll> bfs;  // 0-1 BFS
    vector<ll> d(n, INF);
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back({v, 0}), g[v].push_back({u, 0});
    }
    for (ll i = 0; i < n - 1; ++i) {
        g[i].push_back({i + 1, 1});
        g[i + 1].push_back({i, 1});
    }
    bfs.push_back(0);
    d[0] = 0;
    while (!bfs.empty()) {
        ll par_v = bfs.front();
        bfs.pop_front();
        for (auto &[child_v, wt] : g[par_v]) {
            if (d[par_v] + wt < d[child_v]) {
                d[child_v] = d[par_v] + wt;
                ((wt == 1) ? bfs.push_back(child_v) : bfs.push_front(child_v));
            }
        }
    }
    cout << d[n - 1] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}