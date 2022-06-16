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
#define all(mat) (mat).begin(), (mat).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

struct Matrix {
    static const ll M = MOD - 1;  // P - 1, fermat's litle
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

// Similar = https://www.codechef.com/problems/ECODOWN

/*
    f(x) = c ^ (2x - 6) * f(x - 1) * f(x - 2) * f(x - 3)
    
    ! M1
    if g(x) = c^x f(x), then g(x) = g(x-1)*g(x-2)*g(x-3)..

    ! M2
    f(x) = c^a * f(1)^b * f(2)^c * f(3)^d
    f(x)%MOD, MOD = Prime, then
    f(x) = (c^(a%(x-1)) ... )% MOD <- Fermats little theorem
    thus calculate all powers mod P - 1

    c: 
        a(i) = a(i - 1) + a(i - 2) + a(i - 3) + 2*i - 6
        [a(i) a(i+1) a(i+2) i+3 1] = [a(i-1) a(i) a(i+1) i+2 1] * P1
        [a(n) .. ] = [a(4) a(5) a(6) 7 1] * P ^ (n - 4)
        ! [c5 c6 c7 8 1] = [c4 c5 c6 7 1] * P
    others: 
        b(i) = b(i - 1) + b(i - 2) + b(i - 3)
        ! [a5 a6 a7] = [a4 a5 a6] * P
*/

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void Solution() {
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    auto calculate = [&](Matrix BASE, Matrix P, ll N) {
        P = power(P, N);
        BASE *= P;
        return BASE[0][0];
    };
    ll c_power = calculate(
        Matrix({{2, 6, 14, 7, 1}}),
        Matrix({{0, 0, 1, 0, 0},
                {1, 0, 1, 0, 0},
                {0, 1, 1, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, -6, 1, 1}}),
        n - 4);
    ll f1_power = calculate(
        Matrix({{1, 1, 2}}),
        Matrix({{0, 0, 1},
                {1, 0, 1},
                {0, 1, 1}}),
        n - 4);
    ll f2_power = calculate(
        Matrix({{1, 2, 3}}),
        Matrix({{0, 0, 1},
                {1, 0, 1},
                {0, 1, 1}}),
        n - 4);
    ll f3_power = calculate(
        Matrix({{1, 2, 4}}),
        Matrix({{0, 0, 1},
                {1, 0, 1},
                {0, 1, 1}}),
        n - 4);

    ll ans = 1;
    ans *= power(c, c_power);
    ans %= MOD;
    ans *= power(f1, f1_power);
    ans %= MOD;
    ans *= power(f2, f2_power);
    ans %= MOD;
    ans *= power(f3, f3_power);
    ans %= MOD;
    cout << ans << '\n';
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