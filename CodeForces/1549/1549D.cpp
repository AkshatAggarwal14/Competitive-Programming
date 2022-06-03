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

template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    ll N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(ll(arr.size())), K(ll(log2(N))), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP) {
        LOG[1] = 0;
        for (ll i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (ll i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(ll L, ll R) {
        assert(L <= R);
        ll j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
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
    for (ll i = 0; i < n - 1; ++i) d[i] = a[i + 1] - a[i];
    Sparse_Table<ll> GCD(d, [](const ll &i, const ll &j) {
        return gcd(abs(i), abs(j));
    });
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
