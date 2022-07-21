#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/18051
// https://i.imgur.com/GGBmcEP.png
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
        for (int i = size - 1; i > 0; i--) {
            tree[i] = T::merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    T all_query() { return tree[1]; }
    T query(int p) {
        assert(0 <= p && p < _n);
        return tree[p + size];
    }
    T query(int l, int r) {  // sum on interval [l, r]
        assert(0 <= l && l <= r && r < _n);
        T ansl, ansr;
        for (l += size, r += size; l <= r; l >>= 1, r >>= 1) {
            // printf("%d %d\n", l, r);
            if (l & 1) ansl = T::merge(ansl, tree[l++]);
            if (!(r & 1)) ansr = T::merge(tree[r--], ansr);
        }
        return T::merge(ansl, ansr);
    }

    int kth(int k) {  // returns -1 if not found
        int p = 1;
        if (k > tree[p].sum) return -1;
        while (p < size) {
            p <<= 1;
            if (k > tree[p].sum)
                k -= tree[p++].sum;
        }
        return p - size;
    }

    void update(int p, T value) {  // set value at position p
        assert(0 <= p && p < _n);
        for (tree[p += size] = value; p > 1; p >>= 1)
            tree[p >> 1] = T::merge(tree[p], tree[p ^ 1]);
    }

   private:
    vector<T> tree;
    int _n, size, height;
};

struct Node {
    int sum;
    Node(int val = 0) : sum(val) {}
    static Node merge(const Node &i, const Node &j) {
        Node res;
        res.sum = i.sum + j.sum;
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
        if (a[i]) st.update(i, a[i]);
    }
    while (m--) {
        char type;
        int i;
        cin >> type >> i;
        if (type == '1') {
            a[i] ^= 1;
            st.update(i, a[i]);
        } else {
            cout << st.kth(i + 1) << '\n';
        }
    }
}
