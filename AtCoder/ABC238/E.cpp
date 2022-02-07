#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

struct DSU {
    int N;
    vector<int> par, siz;
    DSU(int n) : N(n) {
        par.resize(N);
        siz.resize(N, 1);
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void unite(int X, int Y) {
        X = root(X);
        Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

// a_l + a_{l+1} + ... a_r = pref_r - pref_{l - 1}
// we know pref_0 = 0
// we want to go from pref_0 to pref_n
// if they are connected then possible.

void Solution() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        dsu.unite(l - 1, r);
    }
    cout << (dsu.same(0, n) ? "Yes\n" : "No\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}