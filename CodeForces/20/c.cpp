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

struct weighted_graph {
    ll n;
    vector<vector<pair<ll, ll>>> g;
    vector<ll> d, pred;
    bool called;
    weighted_graph(ll vertices, ll edges = 0)
        : n(vertices), g(n), d(n, INF), pred(n, -1), called(false) {
        read(edges);
    }
    void read(ll edges) {
        for (ll i = 0, u, v, w; i < edges; ++i) {
            cin >> u >> v >> w, --u, --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    void dijkstra(ll source) {
        if (!called) {
            called = true;
            d[source] = 0;
            set<pair<ll, ll>> s = {{0, source}};  // {distance, node}
            while (!s.empty()) {
                ll from = s.begin()->second;
                s.erase(s.begin());
                for (auto &child : g[from]) {
                    ll to = child.first;
                    ll len = child.second;
                    if (d[to] > d[from] + len) {
                        s.erase({d[to], to});
                        d[to] = d[from] + len;
                        pred[to] = from;
                        s.insert({d[to], to});
                    }
                }
            }
        }
    }
    vector<ll> path(ll source, ll destination) {
        if (!called) dijkstra(source);
        vector<ll> path;
        ll X = destination;
        while (X != -1) {
            path.push_back(X);
            if (X == source) break;
            X = pred[X];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

void Solution() {
    ll n, m;
    cin >> n >> m;
    weighted_graph G(n, m);
    vector<ll> path(G.path(0, n - 1));
    if (G.d[n - 1] == INF) return void(cout << "-1\n");  // unreachable
    for (ll &x : path) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}