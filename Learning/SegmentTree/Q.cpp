/*
    Arr of n integers.
    Q queries:
    1 i v: change ith elemet of Arr to v
    2 l r: Count integers with odd count in subarray.
    n <= 1e4
    q <= 1e5
    Arr[i] <= 1e3
*/

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

// const ll MX = 1001;
const ll MX = 10;  // write here max value of a[i] + 1

int32_t main() {
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<bitset<MX>> a(n);
    for (ll i = 0, num; i < n; ++i) {
        cin >> num, --num;
        a[i][num].flip();
    }
    SegTree<bitset<MX>> st(
        a,
        [](const bitset<MX> &i, const bitset<MX> &j) -> bitset<MX> { return i ^ j; },
        []() -> bitset<MX> { return 0; });
    while (q--) {
        int type, _a, b;
        cin >> type >> _a >> b, --_a, --b;
        if (type == 1) {
            a[_a] = 0;
            a[_a][b].flip();
            st.update(_a, a[_a]);
        } else {
            auto ans = st.query(_a, b);
            cout << ans.count() << '\n';
        }
    }
    return 0;
}

/*
4
3
1 2 3 2
2 1 3
1 2 4
2 1 4
*/
