#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int n1, n2;
            cin >> n1 >> n2;
            mp[n1] = i + 1;
            mp[n2] = i + 1;
        }
        // Find nested range count
        /*
            convert
                1: [2, 3]
                2: [1, 4]

                to: [1 2 3 4]
                    [2 1 1 2] => index in query

        */
        for (auto &[x, y] : mp) {
            a.push_back(y);
        }

        SegTree<int> st(
            2 * n, [](const int &i, const int &j) { return i + j; }, []() { return 0; });

        vector<int> left(n + 1, -1), right(n + 1);

        for (int i = 0; i < 2 * n; ++i) {
            if (left[a[i]] == -1) left[a[i]] = i;
            right[a[i]] = i;
        }
        vector<int> ans(n, -1);

        // x y y x
        // mark left's with 1, when visiting right
        for (int i = 0; i < 2 * n; ++i) {
            if (right[a[i]] == i) {
                st.update(left[a[i]], 1);
                ans[a[i] - 1] = st.query(left[a[i]] + 1, right[a[i]]);
            }
        }
        ll res = 0;
        for (auto &A : ans) res += A;
        dbg(ans);
        cout << res << '\n';
    }
}