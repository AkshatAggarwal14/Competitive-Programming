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

    void _query(int node, int node_lo, int node_hi, int q_lo, int q_hi, ll power) {
        if (node_hi < q_lo || q_hi < node_lo)
            return;  // if disjoint ignore
        if (node_lo == node_hi) {
            if (tree[node] <= power) {
                tree[node] = INF;
                ++ans;
            }
            return;
        }
        int last_in_left = (node_lo + node_hi) / 2;
        if (tree[node << 1] <= power) {
            _query(node << 1, node_lo, last_in_left, q_lo, min(q_hi, last_in_left), power);
        }

        if (tree[node << 1 | 1] <= power) {
            _query(node << 1 | 1, last_in_left + 1, node_hi, max(q_lo, last_in_left + 1), q_hi, power);
        }

        calc(node);
    }

    int ans;
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

    ll query(int l, int r, ll power) {
        assert(0 <= l && l <= r && r < _n);
        ans = 0;
        _query(1, 0, size - 1, l, r, power);
        return ans;
    }
    void update(int p, T x) {
        assert(0 <= p && p < _n);
        _update(1, 0, size - 1, p, p, x);
    }

   private:
    vector<T> tree;
    void calc(int k) { tree[k] = operation(tree[2 * k], tree[2 * k + 1]); }
    op operation;
    id initialize;
    int _n, size, height;
};

void test() {
    int n, m;
    cin >> n >> m;
    SegTree<ll> st(
        n,
        [](const ll &i, const ll &j) { return min(i, j); },
        []() { return INF; });
    while (m--) {
        ll type, h, p;
        int i, l, r;
        cin >> type;
        if (type == 1) {
            cin >> i >> h;
            st.update(i, h);
        } else {
            cin >> l >> r >> p, --r;
            cout << st.query(l, r, p) << '\n';
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
