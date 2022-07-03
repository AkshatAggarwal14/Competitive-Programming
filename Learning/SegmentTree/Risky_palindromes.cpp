#include "bits/stdc++.h"
using namespace std;

template <class T>
class SegTree {
   public:
    SegTree() = default;
    SegTree(int n)
        : SegTree(vector<T>(n, T())) {}
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    SegTree(const vector<T> &v)
        : _n(int(v.size())) {
        height = ceil_pow2(_n);
        size = (1 << height);
        tree.resize(2 * size, T());
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
            return T();  // if disjoint ignore
        int last_in_left = (node_lo + node_hi) / 2;
        return T::merge(_query(2 * node, node_lo, last_in_left, q_lo, q_hi),
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

   private:
    vector<T> tree;
    void calc(int k) { tree[k] = T::merge(tree[2 * k], tree[2 * k + 1]); }
    int _n, size, height;
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const int N = 2001;
    struct Node {
        bitset<N> bset;
        Node() : bset(0) {}
        Node(const bitset<N> &_bset) : bset(_bset) {}
        static Node merge(const Node &A, const Node &B) {
            return Node(A.bset ^ B.bset);
        }
    };
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        a[i].bset[num].flip();
    }
    SegTree<Node> st(a);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {  // 1 i v query sets a[i] = v
            int i, v;
            cin >> i >> v, --i;
            a[i].bset.reset();  // sets all bits of a[i] to 0
            a[i].bset[v].flip();
            st.update(i, a[i]);
        } else {
            int l, r;
            cin >> l >> r, --l, --r;
            auto ans = st.query(l, r);  // checks if subarray can be rearranged to palindrome
            cout << ((ans.bset.count() <= 1) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}

/*
6
1 2 3 1 2 4
4
2 1 4
2 1 5
1 6 3
2 2 6

NO
YES
YES

*/