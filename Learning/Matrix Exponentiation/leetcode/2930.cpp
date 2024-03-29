#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

const ll N = 1'00'005;
const ll MOD = 1e9 + 7;  // 998244353;

struct Matrix {
    static const ll M = MOD;
    static const ll SQMOD = M * M;
    static ll const N = 12;
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
    Matrix &operator+=(const Matrix &rhs) {
        assert(n == rhs.n && m == rhs.m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j) {
                mat[i][j] += rhs[i][j];
                if (mat[i][j] >= M) mat[i][j] -= M;
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

class Solution {
   public:
    int stringCount(int n) {
        if (n < 4) return 0;

        int idx[2][3][2];
        int pos = 0;
        for (int l = 0; l < 2; ++l) {
            for (int e = 0; e < 3; ++e) {
                for (int t = 0; t < 2; ++t) {
                    idx[l][e][t] = pos++;
                }
            }
        }

        Matrix Base(12, 1), Transform(12, 12);
        Base[0][0] = 1;

        vector<vector<pair<int, int>>> transformations(12);  // [[coeff, which_index]]
        for (int l = 0; l < 2; ++l) {
            for (int e = 0; e < 3; ++e) {
                for (int t = 0; t < 2; ++t) {
                    transformations[idx[l][e][t]].push_back({23, idx[l][e][t]});
                    transformations[idx[min(l + 1, 1)][e][t]].push_back({1, idx[l][e][t]});
                    transformations[idx[l][min(e + 1, 2)][t]].push_back({1, idx[l][e][t]});
                    transformations[idx[l][e][min(t + 1, 1)]].push_back({1, idx[l][e][t]});
                }
            }
        }

        for (int row = 0; row < 12; ++row) {
            for (auto &t : transformations[row]) {
                Transform[row][t.second] += t.first;
            }
        }

        return int((power(Transform, n) * Base)[idx[1][2][1]][0]);
    }
};

int main() {
    Solution st;
    cout << st.stringCount(4) << '\n';
    cout << st.stringCount(10) << '\n';
}