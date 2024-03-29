
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class LazySegTree {
   public:
    int n, _n;
    vector<ll> sum;
    // we need to store `d` as when two updates lazily applied to a range, then `d` doubles.
    vector<pair<ll, ll>> lazy;  // {a, d}

    int ceil_pow2(int N) {
        int x = 0;
        while ((1U << x) < (unsigned int)(N)) x++;
        return x;
    }

    LazySegTree(vector<int>& a) : n(int(a.size())) {
        _n = n;
        n = (1 << ceil_pow2(n));
        sum.resize(2 * n);
        lazy.resize(2 * n);

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

    ll AP(ll A, ll N, ll D) {
        return N * (2 * 1LL * A + (N - 1) * 1LL * D) / 2;
    }

    void propagate(int v, int tl, int tr) {
        if (tl == tr) return;

        int mid = (tl + tr) / 2;
        sum[2 * v] += AP(lazy[v].first, (mid - tl + 1), lazy[v].second);
        sum[2 * v + 1] += AP(lazy[v].first + (mid - tl + 1) * lazy[v].second, (tr - (mid + 1) + 1), lazy[v].second);

        lazy[2 * v].first += lazy[v].first;
        lazy[2 * v + 1].first += lazy[v].first + (mid - tl + 1) * lazy[v].second;

        lazy[2 * v].second += lazy[v].second;
        lazy[2 * v + 1].second += lazy[v].second;

        lazy[v].first = 0;
        lazy[v].second = 0;
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

    void update(int v, int tl, int tr, int l, int r, int start) {
        propagate(v, tl, tr);

        if (l <= tl && tr <= r) {
            sum[v] += AP(tl - start + 1, tr - tl + 1, 1);
            lazy[v].first += tl - start + 1;
            lazy[v].second += 1;

            propagate(v, tl, tr);
            return;
        }
        if (tr < l || r < tl) return;

        int tm = (tl + tr) / 2;

        update(2 * v, tl, tm, l, r, start);
        update(2 * v + 1, tm + 1, tr, l, r, start);

        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void update(int l, int r) {
        update(1, 0, _n - 1, l, r, l);
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
            cin >> l >> r, --l, --r;
            seg.update(l, r);
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