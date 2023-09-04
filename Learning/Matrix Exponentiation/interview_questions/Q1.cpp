/*
you have a 20 length circular binary string
do this operation k times,

iterate i from 1 to 20
   if i-1th and i+1th characters are different, set si as 1 else 0

output string after k operations
*/

#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

struct Matrix {
    static const ll M = 2;
    static const ll SQMOD = M * M;
    static ll const N = 20;
    ll mat[N][N];
    ll n, m;
    Matrix(ll _n = N, ll _m = N, ll val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    Matrix(const vector<vector<ll>> &other) {
        n = ll(other.size()), m = ll(other[0].size());
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = other[i][j];
    }
    ll *operator[](ll r) { return mat[r]; }
    const ll *operator[](ll r) const { return mat[r]; }
    static Matrix unit(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; i++)
            res[i][i] = 1;
        return res;
    }
    Matrix &operator+=(const Matrix &rhs) {
        assert(n == rhs.n && m == rhs.m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j) {
                mat[i][j] += rhs[i][j];
                mat[i][j] %= M;
            }
        return *this;
    }
    Matrix operator+(const Matrix &rhs) const {
        Matrix lhs(*this);
        return lhs += rhs;
    }
    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.m == B.n);
        Matrix res(A.n, B.m);
        for (ll i = 0; i < res.n; i++)
            for (ll j = 0; j < res.m; j++) {
                ll sum = 0LL;
                for (ll k = 0; k < A.m; k++) {
                    sum += A[i][k] * B[k][j];
                    sum %= SQMOD;
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

/*
we are given [a0, b0, c0,....t0]

a1 = (t0 + b0) % 2
b1 = (a1 + c0) % 2
c1 = (b1 + d0) % 2
d1 = (c1 + e0) % 2
e1 = (d1 + f0) % 2
.
.
.
s1 = (r1 + t0) % 2
t1 = (s1 + a1) % 2
*/

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, k;
    string s;
    cin >> s >> k;
    n = int(s.size());

    vector<vector<ll>> contri(n, vector<ll>(n, 0));
    for (int i = 0; i + 1 < n; ++i)
        contri[i][i + 1] = 1;

    contri[0][n - 1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            contri[i][j] += contri[i - 1][j];
        }
    }
    for (int j = 0; j < n; ++j) {
        contri[n - 1][j] += contri[0][j];
    }

    Matrix Transform(contri);
    Matrix Base(n, 1, 0);
    for (int i = 0; i < n; ++i) {
        Base[i][0] = int(s[i] - '0');
    }

    Matrix ans = power(Transform, k - 1) * Base;
    for (int i = 0; i < n; ++i) {
        cout << ans[i][0];
    }
    cout << '\n';

    return 0;
}

/*
Input:

6
001011
2

Output:
100101
*/