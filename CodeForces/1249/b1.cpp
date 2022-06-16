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

struct DSU {
    int N;
    vector<int> par, siz;
    DSU(int n) : N(n), par(N), siz(N, 1) {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] != X) par[X] = root(par[X]);
        return par[X];
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void join(int X, int Y) {
        X = root(X), Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
    int get_size(int X) { return siz[root(X)]; }
    int components() {
        int cnt = 0;
        for (int i = 0; i < N; ++i) cnt += (root(i) == i);
        return cnt;
    }
};

void Solution() {
    int n;
    cin >> n;
    vector<int> p(n);
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i], --p[i];
        dsu.join(i, p[i]);
    }
    for (int i = 0; i < n; ++i) cout << dsu.get_size(i) << ' ';
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
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}