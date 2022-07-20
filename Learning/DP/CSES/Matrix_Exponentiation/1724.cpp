#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18 + 5;  // 2 edges of 1e18
struct Matrix {
    static ll const N = 100;
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
    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.m == B.n);
        Matrix res(A.n, B.m, INF);
        for (ll i = 0; i < res.n; i++)
            for (ll j = 0; j < res.m; j++) {
                for (ll k = 0; k < A.m; k++) {
                    res[i][j] = min(res[i][j], A[i][k] + B[k][j]);
                }
            }
        return res;
    }
    friend Matrix power(Matrix base, long long ex) {
        --ex;  //!
        assert(base.n == base.m);
        Matrix res = base;  //!
        while (ex > 0) {
            if (ex & 1) res = res * base;
            base = base * base;
            ex >>= 1;
        }
        return res;
    }
    Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    Matrix Base(n, n, INF);
    while (m--) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--, y--;
        Base[x][y] = min(Base[x][y], w);
    }
    ll ans = power(Base, k)[0][n - 1];
    if (ans == INF) ans = -1;
    cout << ans;
}