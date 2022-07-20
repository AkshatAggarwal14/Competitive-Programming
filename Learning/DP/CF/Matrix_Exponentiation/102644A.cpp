#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using ll = long long;

struct Matrix {
    static ll const N = 2;
    double mat[N][N];
    ll n, m;
    Matrix(ll _n = N, ll _m = N, double val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    double *operator[](ll r) { return mat[r]; }
    const double *operator[](ll r) const { return mat[r]; }
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
                double sum = 0LL;
                for (ll k = 0; k < A.m; k++) {
                    sum += A[i][k] * B[k][j];
                }
                res[i][j] = sum;
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
    friend string to_string(const Matrix &a) {
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
    Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    double p;
    cin >> n >> p;
    // happy[0] = 1, unhappy[0] = 0
    // happy[i] = unhappy[i - 1] * p + happy[i] * (1 - p)
    // unhappy[i] = happy[i - 1] * p + unhappy[i - 1] * (1 - p)
    // p means switches -> happy to unhappy
    // 1 - p means same
    Matrix Base(2, 2);
    Base[0][0] = 1 - p;
    Base[0][1] = p;
    Base[1][0] = p;
    Base[1][1] = 1 - p;
    cout << power(Base, n)[0][0] << '\n';
}