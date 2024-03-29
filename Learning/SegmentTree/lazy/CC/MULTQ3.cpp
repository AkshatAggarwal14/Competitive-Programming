#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
using a3 = array<ll, 3>;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

template <class T, class op = function<T(const T &, const T &)>, class id = function<T()>>
class lazy_seg_tree {
   public:
    lazy_seg_tree() = default;
    lazy_seg_tree(int n, op operation_, id identity_)
        : lazy_seg_tree(vector<T>(n, identity_()), operation_, identity_) {}
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    lazy_seg_tree(const vector<T> &v, op operation_, id identity_)
        : operation(operation_), initialize(identity_), _n(int(v.size())) {
        height = ceil_pow2(_n);
        size = (1 << height);
        tree.resize(2 * size, initialize());
        lazy.resize(2 * size, 0);
        for (int i = 0; i < _n; i++)
            tree[size + i][0] = 1;  // initialise count[0] = 1
        for (int i = size - 1; i >= 1; i--) {
            calc(i);
        }
    }

    T _query(int node, int node_lo, int node_hi, int q_lo, int q_hi) {
        propagate(node, node_lo, node_hi);
        // if range is completely inside [q_lo, q_hi], then just return its ans
        if (q_lo <= node_lo && node_hi <= q_hi)
            return tree[node];
        if (node_hi < q_lo || q_hi < node_lo)
            return initialize();  // if disjoint ignore
        int last_in_left = (node_lo + node_hi) / 2;
        return operation(_query(2 * node, node_lo, last_in_left, q_lo, q_hi),
                         _query(2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi));
    }

    void propagate(int node, int l, int r) {
        if (lazy[node]) {
            a3 nxtNode{0, 0, 0};
            for (int i = 0; i < 3; ++i) {
                nxtNode[(i + lazy[node]) % 3] = tree[node][i];
            }

            tree[node] = nxtNode;

            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void _update(int node, int node_lo, int node_hi, int q_lo, int q_hi) {
        propagate(node, node_lo, node_hi);
        // happens only once when leaf [id, id]
        if (q_lo <= node_lo && node_hi <= q_hi) {
            lazy[node] = 1;
            propagate(node, node_lo, node_hi);
            return;
        }
        // in disjoint just return
        if (node_hi < q_lo || q_hi < node_lo) return;
        int last_in_left = (node_lo + node_hi) / 2;
        _update(2 * node, node_lo, last_in_left, q_lo, q_hi);
        _update(2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi);

        // after updating now set, Post Call Area
        calc(node);
    }

    T query(int l, int r) {
        assert(0 <= l && l <= r && r < _n);
        return _query(1, 0, size - 1, l, r);
    }
    void update(int l, int r) {
        assert(0 <= l && l < _n and 0 <= r && r < _n and l <= r);
        _update(1, 0, size - 1, l, r);
    }

   private:
    vector<T> tree;
    vector<int> lazy;
    void calc(int k) {
        tree[k] = operation(tree[2 * k], tree[2 * k + 1]);
    }
    op operation;
    id initialize;
    int _n, size, height;
};

void test() {
    int n, c;
    cin >> n >> c;
    lazy_seg_tree<a3> lz(
        n,
        [](const a3 &A, const a3 &B) { return a3{A[0] + B[0], A[1] + B[1], A[2] + B[2]}; },
        []() { return a3{0, 0, 0}; });

    while (c--) {
        int type, p, q;
        cin >> type >> p >> q;
        if (type == 0) {
            lz.update(p, q);
        } else {
            cout << lz.query(p, q)[0] << '\n';
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
