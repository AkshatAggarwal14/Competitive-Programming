#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// can use decltype while initialising to make a little bit faster
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

const int N = 2e5 + 5;
const ll INF = 1e18;
void test() {
    int n, q;
    cin >> n >> q;
    vector<ll> pos(N + 5), a(n);
    map<ll, ll> cnt;
    for (auto &A : a) cin >> A, ++pos[A], ++cnt[A];
    SegTree<ll> Max(
        pos, [](const ll &i, const ll &j) { return max(i, j); }, []() { return -INF; });
    SegTree<ll> Min(
        pos, [](const ll &i, const ll &j) { return min(i, j); }, []() { return INF; });
    while (q--) {
        int k;
        ll l;
        cin >> k >> l;
        --k;
        --cnt[a[k]];

        if (cnt[a[k]] == 0) cnt.erase(a[k]);
        --pos[a[k]];
        Max.update(a[k], Max.query(a[k]) - 1);
        Min.update(a[k], Min.query(a[k]) - 1);
        a[k] = l;
        ++pos[a[k]];
        ++cnt[a[k]];
        Max.update(a[k], Max.query(a[k]) + 1);
        Min.update(a[k], Min.query(a[k]) + 1);

        // query
        ll large = (*cnt.rbegin()).first;
        cerr << large << '\n';
        int R = large, L = 0;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (Min.query(M, large) != 0) {
                R = M;
            } else {
                L = M;
            }
        }
        cerr << R << '\n';
        cerr << '\n';
        // [R, large] <- non zero range, find maximum  here
        if (Max.query(R, large) == 2)
            cout << large + 1 << '\n';
        else
            cout << large << '\n';
        // update
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        test();
    }
}