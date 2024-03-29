
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class LazySegTree {
   public:
    int n, _n;
    vector<ll> sum;
    vector<ll> lazyAdd;
    vector<ll> lazySet;

    int ceil_pow2(int N) {
        int x = 0;
        while ((1U << x) < (unsigned int)(N)) x++;
        return x;
    }

    LazySegTree(vector<int>& a) : n(int(a.size())) {
        _n = n;
        n = (1 << ceil_pow2(n));
        sum.resize(2 * n);
        lazyAdd.resize(2 * n);
        lazySet.resize(2 * n);

        build(a, 1, 0, _n - 1);
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            sum[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            sum[v] = sum[v * 2] + sum[v * 2 + 1];
        }
    }

    void propagate(int v, int tl, int tr) {
        if (tl == tr) return;

        int mid = (tl + tr) / 2;
        int lv = 2 * v, rv = 2 * v + 1;

        if (lazySet[v]) {
            lazySet[lv] = lazySet[rv] = lazySet[v];

            sum[lv] = (mid - tl + 1) * lazySet[v];
            sum[rv] = (tr - (mid + 1) + 1) * lazySet[v];

            lazyAdd[lv] = lazyAdd[rv] = 0;
            lazySet[v] = 0;
        } else {
            // left
            if (lazySet[lv]) {
                lazySet[lv] += lazyAdd[v];
                lazyAdd[lv] = 0;
            } else {
                lazyAdd[lv] += lazyAdd[v];
            }
            // right
            if (lazySet[rv]) {
                lazySet[rv] += lazyAdd[v];
                lazyAdd[rv] = 0;
            } else {
                lazyAdd[rv] += lazyAdd[v];
            }

            sum[lv] += (mid - tl + 1) * lazyAdd[v];
            sum[rv] += (tr - (mid + 1) + 1) * lazyAdd[v];
            lazyAdd[v] = 0;
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        propagate(v, tl, tr);

        if (l <= tl && tr <= r)
            return sum[v];

        if (tr < l || r < tl)
            return 0;

        int tm = (tl + tr) / 2;
        return (query(2 * v, tl, tm, l, r) +
                query(2 * v + 1, tm + 1, tr, l, r));
    }

    ll query(int l, int r) {
        return query(1, 0, _n - 1, l, r);
    }

    void add(int v, int tl, int tr, int l, int r, ll val) {
        propagate(v, tl, tr);

        if (l <= tl && tr <= r) {
            sum[v] += (tr - tl + 1) * val;
            if (lazySet[v]) {
                lazySet[v] += val;
            } else {
                lazyAdd[v] += val;
            }
            propagate(v, tl, tr);
            return;
        }
        if (tr < l || r < tl) return;

        int tm = (tl + tr) / 2;

        add(2 * v, tl, tm, l, r, val);
        add(2 * v + 1, tm + 1, tr, l, r, val);

        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void add(int l, int r, ll val) {
        add(1, 0, _n - 1, l, r, val);
    }

    void set(int v, int tl, int tr, int l, int r, ll val) {
        propagate(v, tl, tr);

        if (l <= tl && tr <= r) {
            sum[v] = (tr - tl + 1) * val;
            lazySet[v] = val;
            lazyAdd[v] = 0;
            propagate(v, tl, tr);
            return;
        }
        if (tr < l || r < tl) return;

        int tm = (tl + tr) / 2;

        set(2 * v, tl, tm, l, r, val);
        set(2 * v + 1, tm + 1, tr, l, r, val);

        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void set(int l, int r, ll val) {
        set(1, 0, _n - 1, l, r, val);
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
        } else if (type == 2) {
            int l, r;
            ll x;
            cin >> l >> r >> x, --l, --r;
            seg.set(l, r, x);
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
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}