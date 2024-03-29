#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll MOD = 1e9 + 7;

struct Matrix {
    long long mat[2][2];
    Matrix friend
    operator*(const Matrix &a, const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    c.mat[i][j] += 1LL * a.mat[i][k] * b.mat[k][j] % MOD;
                    c.mat[i][j] %= MOD;
                }
            }
        }
        return c;
    }
    Matrix friend operator+(const Matrix &a, const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
                c.mat[i][j] %= MOD;
            }
        }
        return c;
    }
};

constexpr Matrix BASE{{{1, 1}, {1, 0}}};

Matrix matpow(Matrix base, long long n) {
    Matrix ans{{{1, 0},
                {0, 1}}};
    while (n) {
        if (n & 1)
            ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans;
}

unordered_map<ll, Matrix> dp;

Matrix fib(ll n) {
    if (dp.count(n)) return dp[n];
    return dp[n] = matpow(BASE, n - 1);
}

class LazySegTree {
   public:
    int n, _n;
    vector<Matrix> tree;
    vector<ll> lazyAdd;

    int ceil_pow2(int N) {
        int x = 0;
        while ((1U << x) < (unsigned int)(N)) x++;
        return x;
    }

    LazySegTree(vector<int> &a) : n(int(a.size())) {
        _n = n;
        n = (1 << ceil_pow2(n));
        tree.resize(2 * n, {{{0, 0}, {0, 0}}});
        lazyAdd.resize(2 * n, 0);

        build(a, 1, 0, _n - 1);
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = fib(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void propagate(int v, int tl, int tr) {
        if (tl == tr) return;
        // int mid = (tl + tr) / 2;
        int lv = 2 * v, rv = 2 * v + 1;
        if (lazyAdd[v]) {
            tree[lv] = tree[lv] * fib(lazyAdd[v] + 1);
            tree[rv] = tree[rv] * fib(lazyAdd[v] + 1);
            lazyAdd[lv] += lazyAdd[v];
            lazyAdd[rv] += lazyAdd[v];
            lazyAdd[v] = 0;
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        propagate(v, tl, tr);

        if (l <= tl && tr <= r)
            return tree[v].mat[0][0];

        if (tr < l || r < tl)
            return 0;

        int tm = (tl + tr) / 2;
        return (query(2 * v, tl, tm, l, r) +
                query(2 * v + 1, tm + 1, tr, l, r)) %
               MOD;
    }

    ll query(int l, int r) {
        return query(1, 0, _n - 1, l, r);
    }

    void add(int v, int tl, int tr, int l, int r, ll val) {
        propagate(v, tl, tr);

        if (l <= tl && tr <= r) {
            tree[v] = tree[v] * fib(val + 1);
            lazyAdd[v] += val;
            return;
        }
        if (tr < l || r < tl) return;

        int tm = (tl + tr) / 2;

        add(2 * v, tl, tm, l, r, val);
        add(2 * v + 1, tm + 1, tr, l, r, val);

        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    void add(int l, int r, ll val) {
        add(1, 0, _n - 1, l, r, val);
    }
};

void test() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    LazySegTree seg(a);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x, --l, --r;
            seg.add(l, r, x);
        } else {
            int l, r;
            cin >> l >> r, --l, --r;
            cout << seg.query(l, r) << '\n';
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
