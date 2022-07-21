#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    // only Recursion needed to solve !!!
    int _kth_max_after_l(int node, int node_lo, int node_hi, int k, int q_lo) {
        if (tree[node].mx < k) return -1;        // if max value in current subtree < k
        if (node_hi < q_lo) return -1;           // no intersection
        if (node_lo == node_hi) return node_lo;  // if reach leaf
        int last_in_left = (node_lo + node_hi) >> 1;
        int res = _kth_max_after_l(2 * node, node_lo, last_in_left, k, q_lo);
        if (res == -1)  // if cant find for left subtree, go for right
            res = _kth_max_after_l(2 * node + 1, last_in_left + 1, node_hi, k, q_lo);
        return res;
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
    int kth_max_after_l(int k, int l) {
        return _kth_max_after_l(1, 0, size - 1, k, l);
    }

   private:
    vector<T> tree;
    void calc(int k) { tree[k] = T::merge(tree[2 * k], tree[2 * k + 1]); }
    int _n, size, height;
};

struct Node {
    int mx;
    Node(int val = 0) : mx(val) {}
    static Node merge(const Node &i, const Node &j) {
        Node res;
        res.mx = max(i.mx, j.mx);
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    SegTree<Node> st(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.update(i, a[i]);
    }
    while (m--) {
        char type;
        int i, v;
        cin >> type >> i >> v;
        if (type == '1') {
            a[i] = v;
            st.update(i, a[i]);
        } else {
            cout << st.kth_max_after_l(i, v) << '\n';
        }
    }
}
