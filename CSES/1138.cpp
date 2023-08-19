#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

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
    ll val;
    Node(ll v = 0) : val(v) {}
    static Node merge(const Node &i, const Node &j) {
        return Node(i.val + j.val);
    }
};

void test() {
    int n, q;
    cin >> n >> q;
    vector<int> value(n);
    for (auto &x : value) cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> first(n), last(n);
    vector<Node> tour;
    function<void(int, int)> euler = [&](int node, int par) {
        first[node] = int(tour.size());
        tour.push_back(Node(value[node]));
        for (auto &child : g[node]) {
            if (child != par) {
                euler(child, node);
            }
        }
        last[node] = int(tour.size());
        tour.push_back(Node(-value[node]));  //! to make others zero and only take path until node from root
    };

    euler(0, -1);

    SegTree<Node> st(tour);

    while (q--) {
        int type, s;
        ll x;
        cin >> type;
        if (type == 1) {
            cin >> s >> x, --s;
            st.update(first[s], Node(x));
            st.update(last[s], Node(-x));
        } else {
            cin >> s, --s;
            cout << st.query(first[0], first[s]).val << '\n';
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
