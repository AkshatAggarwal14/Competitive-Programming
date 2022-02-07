#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const ll MOD = 1e9 + 7;

struct Matrix {
    static const ll M = MOD;
    static const ll SQMOD = M * M;
    static ll const N = 10;
    ll mat[N][N];
    ll n, m;
    Matrix(ll _n = N, ll _m = N, ll val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    Matrix(const vector<vector<ll>> &&other) {
        n = ll(other.size());
        m = ll(other[0].size());
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = other[i][j];
    }
    Matrix &operator=(const vector<vector<ll>> &&other) {
        return *this = Matrix(forward<decltype(other)>(other));
    }
    ll *operator[](ll r) { return mat[r]; }
    const ll *operator[](ll r) const { return mat[r]; }
    static Matrix unit(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.m == B.n);
        Matrix res(A.n, B.m);
        for (ll i = 0; i < res.n; i++)
            for (ll j = 0; j < res.m; j++) {
                ll sum = 0LL;
                for (ll k = 0; k < A.m; k++) {
                    sum += A[i][k] * B[k][j];
                    if (sum >= SQMOD) sum -= SQMOD;
                }
                res[i][j] = (sum % M);
            }
        return res;
    }
    friend Matrix power(Matrix base, long long ex) {
        assert(base.n == base.m);
        Matrix res = Matrix::unit(base.n);
        while (ex > 0) {
            if (ex & 1) res = res * base;
            base = base * base;
            ex >>= 1;
        }
        return res;
    }
    Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
};

void Solution() {
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    // [f1 f2 9 3 1] = [f0 f1 4 2 1] * P
    // [f_n f_{n+1} (n+2)^2 (n+2) 1] = [f0 f1 4 2 1] * P^n
    Matrix Base({{2, 3, 4, 2, 1}});
    Matrix Transform(
        {{0, b, 0, 0, 0},
         {1, a, 0, 0, 0},
         {0, c, 1, 0, 0},
         {0, d, 2, 1, 0},
         {0, e, 1, 1, 1}});
    Transform = power(Transform, n);
    Base *= Transform;
    cout << Base[0][0] % MOD << '\n';
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