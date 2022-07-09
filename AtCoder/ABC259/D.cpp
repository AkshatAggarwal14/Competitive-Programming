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
    int n;
    cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<array<ll, 3>> circle(n);
    for (auto &[x, y, r] : circle) cin >> x >> y >> r;
    auto intersect = [&](int i, int j) {
        // d(c1, c2) <= r1 + r2
        auto [x1, y1, r1] = circle[i];
        auto [x2, y2, r2] = circle[j];
        ll d_sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        ll r_sum = r1 * r1 + r2 * r2 + 2 * r1 * r2;
        ll r_sum_ = r1 * r1 + r2 * r2 - 2 * r1 * r2;
        if (d_sq <= r_sum && d_sq >= r_sum_) return true;
        return false;
    };
    auto on_circ = [&](int i, ll x, ll y) {
        auto [X, Y, R] = circle[i];
        ll d_sq = (x - X) * (x - X) + (y - Y) * (y - Y);
        return d_sq == R * R;
    };
    int st = -1, en = -1;
    for (int i = 0; i < n; ++i) {
        if (on_circ(i, sx, sy)) st = i;
        if (on_circ(i, tx, ty)) en = i;
    }
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intersect(i, j)) dsu.unite(i, j);
        }
    }
    cout << (dsu.same(st, en) ? "Yes\n" : "No\n");
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
