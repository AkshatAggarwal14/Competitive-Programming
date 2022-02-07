#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

// works only for idempotent functions f(a, a) = a
// Updates not supported
template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    ll N, K;
    vector<vector<T>> st;
    vector<ll> LOG;
    U op;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(ll(arr.size())), K(__lg(N)), op(OP) {
        st.resize(N, vector<T>(K + 1));
        LOG.resize(N + 1);
        LOG[1] = 0;
        for (ll i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (ll i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(ll L, ll R) {
        if (L > R) return T();
        ll j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void Solution() {
    map<ll, ll> cnt;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    Sparse_Table<ll> st(a, [](ll A, ll B) { return gcd(A, B); });

    for (ll i = 0; i < n; ++i) {
        // gcd decreases as we move right
        // T T F F F -> gcd(0, m) >= a[0]
        // for each i, we find last a[i], such that gcd(i, x) is equal to a[i] to find its count
        for (ll last = i; last < n;) {
            // last index for given val
            ll l = last, r = n - 1, count = 1;
            --l, ++r;
            while (r > l + 1) {
                ll m = (l + r) / 2;
                if (st.query(i, m) >= st.query(i, last)) {
                    l = m;
                    count = m - last + 1;
                } else {
                    r = m;
                }
            }
            cnt[st.query(i, last)] += count;
            last = l + 1;  // for each i, scan how many are equal.
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll qi;
        cin >> qi;
        cout << cnt[qi] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}