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
        if (k > tree[p].mx) return -1;
        while (p < size) {
            p <<= 1;
            if (k > tree[p].mx) ++p;
        }
        return p - size;
    }

    int descent_right(int k, int l) {
        // [l, n - 1] here the suffix is divided into various smaller binary trees, rooted at an odd root
        // odd because if an even subtree was in range, then its right sibling would also be in range, thus making its parent to be in range -> thus has to be odd

        // here we divide p by 2 atmost log(n) times and reach 1
        int p = l + size;
        while (p % 2 == 0) p /= 2;
        do {
            // for a subtree
            if (tree[p].mx >= k) {  // answer in this subtree
                while (p < size) {
                    p <<= 1;
                    if (k > tree[p].mx) ++p;  // move to right child
                }
                return p - size;
            } else {
                ++p;  // move to next subtree
                while (p % 2 == 0) p /= 2;
            }
        } while (p != 1);
        return -1;
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
    ll v;
    Node(ll val = 0) : v(val) {}
    static Node merge(const Node &i, const Node &j) {
        return Node{i.v + j.v};
    }
};

void test() {
    int n, q;
    cin >> n >> q;
    vector<ll> val(n);
    for (auto &v : val) cin >> v;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> euler, first(n), last(n);
    auto dfs = [&](const auto &self, int node = 0, int parent = -1) -> void {
        first[node] = int(euler.size());
        for (int neighbor : g[node])
            if (neighbor != parent)
                self(self, neighbor, node);
        euler.push_back(node);
        last[node] = int(euler.size()) - 1;
    };
    dfs(dfs);
    SegTree<Node> st(n);
    for (int i = 0; i < n; ++i) st.update(last[i], val[i]);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            ll x;
            cin >> s >> x, --s;
            val[s] = x;
            st.update(last[s], val[s]);
        } else {
            int s;
            cin >> s, --s;
            cout << st.query(first[s], last[s]).v << '\n';
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
