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
    SegTree(ll n, op operation_, id identity_)
        : SegTree(vector<T>(n, identity_()), operation_, identity_) {}
    ll ceil_pow2(ll n) {
        ll x = 0;
        while ((1U << x) < (unsigned long long int)(n)) x++;
        return x;
    }
    SegTree(const vector<T> &v, op operation_, id identity_)
        : operation(operation_), initialize(identity_), _n(ll(v.size())) {
        height = ceil_pow2(_n);
        size = (1 << height);
        tree.resize(2 * size, initialize());
        for (ll i = 0; i < _n; i++) tree[size + i] = v[i];
        for (ll i = size - 1; i >= 1; i--) {
            calc(i);
        }
    }

    T _query(ll node, ll node_lo, ll node_hi, ll q_lo, ll q_hi) {
        // if range is completely inside [q_lo, q_hi], then just return its ans
        if (q_lo <= node_lo && node_hi <= q_hi)
            return tree[node];
        if (node_hi < q_lo || q_hi < node_lo)
            return initialize();  // if disjoint ignore
        ll last_in_left = (node_lo + node_hi) / 2;
        return operation(_query(2 * node, node_lo, last_in_left, q_lo, q_hi),
                         _query(2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi));
    }

    void _update(ll node, ll node_lo, ll node_hi, ll q_lo, ll q_hi, T value) {
        // happens only once when leaf [id, id]
        if (q_lo <= node_lo && node_hi <= q_hi) {
            tree[node] = value;
            return;
        }
        // in disjoint just return
        if (node_hi < q_lo || q_hi < node_lo) return;
        ll last_in_left = (node_lo + node_hi) / 2;
        _update(2 * node, node_lo, last_in_left, q_lo, q_hi, value);
        _update(2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi, value);

        // after updating now set, Post Call Area
        calc(node);
    }

    T query(ll l, ll r) {
        assert(0 <= l && l <= r && r < _n);
        return _query(1, 0, size - 1, l, r);
    }
    void update(ll p, T x) {
        assert(0 <= p && p < _n);
        _update(1, 0, size - 1, p, p, x);
    }

   private:
    vector<T> tree;
    void calc(ll k) { tree[k] = operation(tree[2 * k], tree[2 * k + 1]); }
    op operation;
    id initialize;
    ll _n, size, height;
};

// In difference array d[i] = A[i + 1] - A[i]
// gcd[d[i, j - 1]] must be > 1, for friend group A[i, j]

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    if (n == 1) return void(cout << "1\n");
    vector<ll> d(n - 1);
    for (ll i = 0; i < n - 1; ++i) d[i] = abs(a[i + 1] - a[i]);
    SegTree<ll> GCD(
        d,
        [](const ll &i, const ll &j) {
            return gcd(i, j);
        },
        []() { return 0LL; });
    ll ans = 1;
    for (ll i = 0; i < n - 1; ++i) {
        ll L = i, R = n - 2;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            ll q = GCD.query(i, M);
            if (q > 1) {
                L = M;
            } else {
                R = M;
            }
        }
        if (L == i - 1) continue;
        ans = max(ans, (L + 1) - i + 1);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
