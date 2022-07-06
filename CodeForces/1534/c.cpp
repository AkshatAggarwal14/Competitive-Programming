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

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

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
    DSU dsu(n);
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i, --i;
    for (int &i : b) cin >> i, --i;
    for (int i = 0; i < n; ++i) dsu.unite(a[i], b[i]);
    cout << power(2, dsu.components) << '\n';
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
