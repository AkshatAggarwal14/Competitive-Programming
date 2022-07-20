#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// can use decltype while initialising to make a little bit faster
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

struct Node {
    ll best, sum, pref, suff;
    Node(ll val = 0) : sum(val) {
        best = pref = suff = max(val, 0LL);
    }
    static Node merge(const Node &i, const Node &j) {
        Node res;
        res.pref = max(i.pref, i.sum + j.pref);
        res.suff = max(j.suff, i.suff + j.sum);
        res.sum = i.sum + j.sum;
        res.best = max({i.best, j.best, i.suff + j.pref});
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    SegTree<Node> a(n);
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        a.update(i, num);
    }
    cout << a.all_query().best << '\n';
    while (m--) {
        int i;
        ll v;
        cin >> i >> v;
        a.update(i, v);
        cout << a.all_query().best << '\n';
    }
}