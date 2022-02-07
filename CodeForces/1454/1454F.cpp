#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

// works only for idempotent functions f(a, a) = a
// Updates not supported
template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    int N, K;
    vector<vector<T>> st;
    vector<int> LOG;
    U op;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(int(arr.size())), K(__lg(N)), op(OP) {
        st.resize(N, vector<T>(K + 1));
        LOG.resize(N + 1);
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(int L, int R) {
        if (L > R) return T();
        int j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void Solution() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Sparse_Table<ll> MIN(a, [](ll A, ll B) { return min(A, B); });
    // dont need sparse table for MAX, only need pref and suff
    vector<ll> pref_MAX(n + 1), suff_MAX(n + 1);
    pref_MAX[1] = a[1], suff_MAX[n] = a[n];
    for (ll i = 2; i <= n; ++i) pref_MAX[i] = max(pref_MAX[i - 1], a[i]);
    for (ll i = n - 1; i >= 1; --i) suff_MAX[i] = max(suff_MAX[i + 1], a[i]);

    // fix x, then BS for y
    for (int x = 1; x <= n; ++x) {
        int l = x + 1, r = n - 1;
        --l, ++r;
        ll max_x = pref_MAX[x];  //! [1, x]
        //   max  |       min      |    max
        // 1 .. x | x+1 x+2 .. m-1 | m m+1 .. n

        // for a fixed x, in [x+1, n], if we move right
        // from [x+1, m] U [m+1, n] to [x+1, m+1] U [m+2, n], min_y can decrease and max_z can decrease
        while (r > l + 1) {
            int m = (l + r) / 2;
            ll min_y = MIN.query(x + 1, m);  //! [x+1, m]
            ll max_z = suff_MAX[m + 1];      //! [m+1, n]
            if (max_x == min_y && max_x == max_z) {
                cout << "YES\n";
                cout << x << ' ' << (m - x) << ' ' << (n - m) << '\n';
                return;
            }

            if (max_x <= min_y && max_x <= max_z) {
                l = m;
            } else {
                r = m;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}