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

struct Matrix {
    ll n, m;
    vector<vector<ll>> mat;
    Matrix(ll N, ll M, ll value = 0, bool identical = false) : n(N), m(M) {
        mat.resize(N, vector<ll>(M, value));
        if (identical) {
            assert(N == M);
            for (ll i = 0; i < N; ++i) mat[i][i] = 1;
        }
    }
    Matrix operator*(const Matrix &b) {
        assert(m == b.n);
        Matrix res(n, b.m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < b.m; ++j)
                for (ll k = 0; k < m; ++k)
                    res.mat[i][j] += mat[i][k] * b.mat[k][j];
        return res;
    }
    Matrix operator+(const Matrix &b) {
        assert(n == b.n && m == b.m);
        Matrix res(n, m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                res.mat[i][j] = mat[i][j] + b.mat[i][j];
        return res;
    }
    friend Matrix power(Matrix a, ll p);
    friend string to_string(const Matrix &a);
};

Matrix power(Matrix a, ll p) {
    assert(a.n == a.m);             // square matrix
    Matrix res(a.n, a.m, 0, true);  // identical matrix
    while (p) {
        if (p & 1) res = a * res;
        p /= 2;
        a = a * a;
    }
    return res;
}

string to_string(const Matrix &a) {
    string res = "\n";
    for (ll i = 0; i < a.n; ++i) {
        res += '{';
        for (ll j = 0; j < a.m; ++j) {
            res += std::to_string(a.mat[i][j]);
            if (j != a.m - 1) res += ", ";
        }
        res += "}\n";
    }
    res.append("\n");
    return res;
}

// [1 an-1 an] = [1 an-2 an-1]* [P]
// [1 an a(n+1)] = [1 a0 a1]* [P]^n
void Solution() {
    ll n;
    cin >> n;
    Matrix base(1, 3), transform(3, 3);
    base.mat = {{1, 2, 3}};  // 1 a0 a1
    transform.mat = {{1, 0, 2}, {0, 0, -1}, {0, 1, 2}};
    cout << (base * power(transform, n)).mat[0][1] << '\n';  // an
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