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

template <class T, class U = function<T(const T &, const T &)>, class V = function<T()>>
class Sparse_Table {
    int N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;
    V id;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP, const V &ID)
        : N(int(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP), id(ID) {
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T slow_query(int L, int R) {
        T res = id();
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                res = op(res, st[L][j]);
                L += (1 << j);
            }
        }
        return res;
    }
    T query(int L, int R) {
        if (L > R) return id();
        int j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void test() {
    int n, m;
    cin >> n >> m;
    // move up, then right/left, then down
    vector<int> a(m);
    for (auto &A : a) cin >> A, A = n - A;
    dbg(a);
    Sparse_Table<int> st(
        a,
        [](const int &i, const int &j) { return min(i, j); },
        []() { return INT_MAX; });
    int q;
    cin >> q;
    while (q--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k, --ys, --yf;
        xf = n - xf, xs = n - xs;
        dbg(xs, ys, xf, yf, k);
        if (abs(ys - yf) % k != 0 || abs(xs - xf) % k != 0) {
            cout << "NO\n";
            continue;
        }
        xs %= k;
        xf %= k;
        if (yf > ys)
            swap(yf, ys);
        int mini = st.query(yf, ys);
        dbg(yf, ys, mini, q);
        if (xs >= mini)
            cout << "NO\n";
        else
            cout << "YES\n";
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
