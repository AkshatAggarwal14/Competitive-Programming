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

struct DSU {
    int N;
    vector<int> par, siz;
    int components;
    DSU(int n) : N(n), par(N), siz(N, 1), components(N) {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] != X) par[X] = root(par[X]);
        return par[X];
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void unite(int X, int Y) {
        X = root(X), Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        --components;
    }
    int get_size(int X) { return siz[root(X)]; }
};

void test() {
    struct pt {
        ll x, y, p;
    };
    struct Edge {
        ll w = INF, to = -1;
    };

    int n;
    cin >> n;
    DSU dsu(n);
    vector<pt> a(n);
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    for (auto &[x, y, p] : a) cin >> x >> y >> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                adj[i][j] = 0;
                continue;
            }
            ll dist = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
            ll w = (dist + a[i].p - 1) / a[i].p;
            adj[i][j] = w;
        }
    }
    dbg(adj);
    ll res = INF;
    auto _adj = adj;
    for (int root = 0; root < n; ++root) {
        ll ans = 0;
        adj = _adj;
        vector<bool> selected(n, false);
        vector<Edge> min_e(n);
        min_e[root].w = 0;

        for (ll i = 0; i < n; ++i) {
            ll v = -1;
            for (ll j = 0; j < n; ++j) {
                if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                    v = j;
            }
            selected[v] = true;
            ans = max(ans, min_e[v].w);
            for (ll to = 0; to < n; ++to) {
                if (adj[v][to] < min_e[to].w)
                    min_e[to] = {adj[v][to], v};
            }
        }
        res = min(res, ans);
    }
    cout << res << '\n';
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
