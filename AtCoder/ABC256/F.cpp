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
const ll MOD = 998244353;

ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}
ll inverse(ll a, ll m = MOD) { return modpow(a, m - 2, m); }

template <class T, class op = function<T(const T &, const T &)>, class id = function<T()>>
class SegTree {
   public:
    SegTree() = default;
    SegTree(int n, op operation_, id identity_)
        : SegTree(vector<T>(n, identity_()), operation_, identity_) {}
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    SegTree(const vector<T> &v, op operation_, id identity_)
        : operation(operation_), initialize(identity_), _n(int(v.size())) {
        height = ceil_pow2(_n);
        size = (1 << height);
        tree.resize(2 * size, initialize());
        for (int i = 0; i < _n; i++) tree[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            calc(i);
        }
    }

    T _query(int node, int node_lo, int node_hi, int q_lo, int q_hi) {
        // if range is completely inside [q_lo, q_hi], then just return its ans
        if (q_lo <= node_lo && node_hi <= q_hi)
            return tree[node];
        if (node_hi < q_lo || q_hi < node_lo)
            return initialize();  // if disjoint ignore
        int last_in_left = (node_lo + node_hi) / 2;
        return operation(_query(2 * node, node_lo, last_in_left, q_lo, q_hi),
                         _query(2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi));
    }

    void _update(int node, int node_lo, int node_hi, int q_lo, int q_hi, T value) {
        // happens only once when leaf [id, id]
        if (q_lo <= node_lo && node_hi <= q_hi) {
            tree[node] = value;
            return;
        }
        // in disjoint just return
        if (node_hi < q_lo || q_hi < node_lo) return;
        int last_in_left = (node_lo + node_hi) / 2;
        _update(2 * node, node_lo, last_in_left, q_lo, q_hi, value);
        _update(2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi, value);

        // after updating now set, Post Call Area
        calc(node);
    }

    T _kth_order(int node, int node_lo, int node_hi, T k) {
        if (node_lo == node_hi) return node_lo;
        int last_in_left = (node_lo + node_hi) >> 1;
        if (tree[2 * node] >= k) return _kth_order(2 * node, node_lo, last_in_left, k);
        return _kth_order(2 * node + 1, last_in_left + 1, node_hi, k - tree[2 * node]);
    }

    T all_query() { return tree[1]; }
    T query(int p) {
        assert(0 <= p && p < _n);
        return tree[p + size];
    }
    T query(int l, int r) {
        assert(0 <= l && l <= r && r < _n);
        return _query(1, 0, size - 1, l, r);
    }
    void update(int p, T x) {
        assert(0 <= p && p < _n);
        _update(1, 0, size - 1, p, p, x);
    }
    T kth_order(T k) {
        assert(k <= tree[1]);
        return _kth_order(1, 0, size - 1, k);
    }

   private:
    vector<T> tree;
    void calc(int k) { tree[k] = operation(tree[2 * k], tree[2 * k + 1]); }
    op operation;
    id initialize;
    int _n, size, height;
};

void test() {
    // for x >= i, a_i contributes to b_x, 1 time
    // a_i contributed to c_x, (x - i + 1) times
    // a_i contributed to d_x, (x - i + 1) * (x - i + 2) / 2 times n*(n+1)/2
    // d_i = Sigma (a_i * ((x - i + 1) * (x - i + 2) / 2)) from i = 0 to x
    // expand d_i and break into a_i, i * a_i, i * i * a_i
    // so maintain one segtree each for a_i, i * a_i, i * i * a_i
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    SegTree<ll> A(
        n, [](const ll &a_, const ll &b_) { return add(a_, b_); }, []() { return 0LL; });
    auto iA = A, iiA = A;
    ll two_inv = inverse(2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ll val = a[i];
        A.update(i, val);
        val = mul(i, val);
        iA.update(i, val);
        val = mul(i, val);
        iiA.update(i, val);
    }
    while (q--) {
        int type, x;
        ll v;
        cin >> type >> x, --x;
        if (type == 1) {
            cin >> v;
            A.update(x, v);
            v = mul(x, v);
            iA.update(x, v);
            v = mul(x, v);
            iiA.update(x, v);

        } else {
            ll sum = 0;
            sum = add(sum, iiA.query(0, x));
            sum = add(sum, mul(mul(-1, 2 * x + 3), iA.query(0, x)));
            sum = add(sum, mul(mul(x + 1, x + 2), A.query(0, x)));
            sum = mul(sum, two_inv);
            cout << sum << '\n';
        }
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
