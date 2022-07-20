#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using ll = long long;

struct Matrix {
    static ll const N = 100;
    unsigned int mat[N][N];  // will take care of MOD
    ll n, m;
    Matrix(ll _n = N, ll _m = N, unsigned int val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    unsigned int *operator[](ll r) { return mat[r]; }
    const unsigned int *operator[](ll r) const { return mat[r]; }
    static Matrix unit(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    Matrix &operator+=(const Matrix &rhs) {
        assert(n == rhs.n && m == rhs.m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j) {
                mat[i][j] += rhs[i][j];
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
                unsigned int sum = 0LL;
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
    /*
        (i, j) can be reached by    1. (i + 1, j + 2)
                                    2. (i + 1, j - 2)
                                    3. (i + 2, j + 1)
                                    4. (i + 2, j - 1)
                                    5. (i - 1, j + 2)
                                    6. (i - 1, j - 2)
                                    7. (i - 2, j + 1)
                                    8. (i - 2, j - 1)
        make 64 x 64 matrix, and make transform matrix of 64 x 1

        a row in base matrix has marked values of cells from where we can reach given point in Transform matrix
     */

    //? Naive DP
    /*
    int k;
    cin >> k;
    // These 64 variables change k times -> "ans" and "dp[8][8]/dp[64]"
    // which make dp[65] -> last index is answer
    unsigned int dp[65] = {0};
    dp[0] = 1;
    // [dp[0] .. dp[63] ans[]]
    // dp[0]-dp[63] is ways to be at ith cell after k moves
    // ans[] is answer for k - 1 moves
    for (int _ = 0; _ <= k; ++_) {  // thus we need 1 more move
        unsigned int ndp[65] = {0};
        for (int cell = 0; cell < 64; ++cell) {
            int row = cell / 8, col = cell % 8;
            for (int dr : {-2, -1, 1, 2}) {
                for (int dc : {-2, -1, 1, 2}) {
                    if (abs(dr) != abs(dc)) {
                        int nrow = row + dr, ncol = col + dc;
                        if (nrow < 8 && nrow >= 0 && ncol >= 0 && ncol < 8) {
                            int ncell = nrow * 8 + ncol;
                            ndp[ncell] += dp[cell];
                        }
                    }
                }
            }
        }
        ndp[64] += dp[64];                              // add previous answers
        for (int i = 0; i < 64; ++i) ndp[64] += dp[i];  // add this
        swap(dp, ndp);
    }
    cout << dp[64] << '\n';
    */

    int k;
    cin >> k;
    Matrix Base(65, 65, 0);
    for (int cell = 0; cell < 64; ++cell) {
        int row = cell / 8, col = cell % 8;
        for (int dr : {-2, -1, 1, 2}) {
            for (int dc : {-2, -1, 1, 2}) {
                if (abs(dr) != abs(dc)) {
                    int nrow = row + dr, ncol = col + dc;
                    if (nrow < 8 && nrow >= 0 && ncol >= 0 && ncol < 8) {
                        int ncell = nrow * 8 + ncol;
                        Base[cell][ncell] = 1;
                    }
                }
            }
        }
        Base[cell][64] = 1;
    }
    Base[64][64] = 1;
    cout << power(Base, k + 1)[0][64] << '\n';
}