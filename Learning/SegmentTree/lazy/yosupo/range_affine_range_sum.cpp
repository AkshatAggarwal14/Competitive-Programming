
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

class LazySegTree {
    int n;
    vector<ll> tree, lazyB, lazyC;

    ll build(int i, int l, int r, vector<ll>& arr) {
        if (l == r) return tree[i] = arr[l];

        int mid = (l + r) / 2;
        ll a = build(2 * i + 1, l, mid, arr),
           b = build(2 * i + 2, mid + 1, r, arr);
        return tree[i] = (a + b) % MOD;
    }

    ll query(int i, int tl, int tr, int ql, int qr) {
        push(i, tl, tr);

        if (ql <= tl && tr <= qr) return tree[i];
        if (tr < ql || qr < tl) return 0;

        int mid = (tl + tr) / 2;
        ll a = query(2 * i + 1, tl, mid, ql, qr),
           b = query(2 * i + 2, mid + 1, tr, ql, qr);
        return (a + b) % MOD;
    }

    void push(int v, int l, int r) {
        int lv = v * 2 + 1, rv = v * 2 + 2;

        tree[v] = ((tree[v] * lazyB[v]) + (r - l + 1) * lazyC[v]) % MOD;

        if (l != r) {
            (lazyB[lv] *= lazyB[v]) %= MOD;
            (lazyB[rv] *= lazyB[v]) %= MOD;

            lazyC[lv] = ((lazyB[v] * lazyC[lv]) % MOD + lazyC[v]) % MOD;
            lazyC[rv] = ((lazyB[v] * lazyC[rv]) % MOD + lazyC[v]) % MOD;
        }

        lazyB[v] = 1;
        lazyC[v] = 0;
    }

    ll update(int i, int tl, int tr, int ql, int qr, ll b, ll c) {
        push(i, tl, tr);

        if (tr < ql || qr < tl)
            return tree[i];

        if (ql <= tl && tr <= qr) {
            (lazyB[i] *= b) %= MOD;
            lazyC[i] = ((b * lazyC[i]) % MOD + c) % MOD;
            push(i, tl, tr);  // if lazy is set, current node also needs the answer in its node
            return tree[i];
        }

        int mid = (tl + tr) / 2;
        ll A = update(2 * i + 1, tl, mid, ql, qr, b, c),
           B = update(2 * i + 2, mid + 1, tr, ql, qr, b, c);
        return tree[i] = (A + B) % MOD;
    }

   public:
    LazySegTree(vector<ll>& arr) : n(int(arr.size())) {
        tree = vector<ll>(4 * n, 0);  // sum
        lazyB = vector<ll>(4 * n, 1);
        lazyC = vector<ll>(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    void update(int l, int r, ll b, ll c) {
        if (l > r) return;
        update(0, 0, n - 1, l, r, b, c);
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        return query(0, 0, n - 1, l, r);
    }
};

void test() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    LazySegTree seg(a);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r;
            ll b, c;
            cin >> l >> r >> b >> c, --r;
            seg.update(l, r, b, c);
        } else {
            int l, r;
            cin >> l >> r, --r;
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