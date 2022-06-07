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
    vector<int> par, siz, mini, maxi;
    int components;
    DSU(int n) : N(n), par(N), siz(N, 1), mini(N), maxi(N), components(N) {
        for (int i = 0; i < N; i++) par[i] = i, mini[i] = i, maxi[i] = i;
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
        mini[Y] = min(mini[X], mini[Y]);
        maxi[Y] = max(maxi[X], maxi[Y]);
        mini[X] = INT_MAX, maxi[X] = INT_MIN;
        --components;
    }
    int get_size(int X) { return siz[root(X)]; }
};

void test() {
    int n, m, a, b;
    string s;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--) {
        cin >> s >> a, a = dsu.root(a);
        if (s == "get")
            cout << dsu.mini[a] << ' ' << dsu.maxi[a] << ' ' << dsu.siz[a] << '\n';
        else
            cin >> b, dsu.unite(a, b);
    }
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
