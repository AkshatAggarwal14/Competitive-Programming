#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

template <class T>
class Sparse_Table {
    int N, K;
    vector<int> LOG;
    vector<vector<T>> st;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr)
        : N(int(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)) {
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = (st[i][j - 1] + st[i + (1 << (j - 1))][j - 1]);
    }
    T query(int L, int R) {
        T res = 0;
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                res += st[L][j];
                L += (1 << j);
            }
        }
        return res;
    }
};

void test() {
    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    for (int x = 0; x <= n - 3; ++x) {
        // x < y < z < w
        // pref[y - 1] - pref[x - 1] = P as y increases, pref[y - 1] - P increases
        int L = x + 1, R = n - 2;
        --L, ++R;
        int y = -1, z = -1, w = -1;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (pref[M] - p <= pref[x]) {
                L = M;
                y = L;
            } else {
                R = M;
            }
        }
        if (y == -1 || pref[y] - pref[x] != p) continue;

        L = y + 1, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (pref[M] - q <= pref[y]) {
                L = M;
                z = L;
            } else {
                R = M;
            }
        }
        if (z == -1 || pref[z] - pref[y] != q) continue;

        L = z + 1, R = n;
        --L, ++R;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (pref[M] - r <= pref[z]) {
                L = M;
                w = L;
            } else {
                R = M;
            }
        }
        if (w == -1 || pref[w] - pref[z] != r) continue;
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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
