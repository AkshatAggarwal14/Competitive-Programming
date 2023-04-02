#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

// https://github.com/naman1601/cp-templates/blob/main/mint.sublime-snippet
template <int Modulus = MOD>
struct Mint {
    int value;

    Mint(long long v = 0) {
        value = int(v % ll(Modulus));
        if (value < 0) value += Modulus;
    }
    Mint(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }
    friend string to_string(const Mint& a) { return to_string(a.value); }
    Mint& operator+=(Mint const& b) {
        value = ((value + b.value) % Modulus + Modulus) % Modulus;
        return *this;
    }
    Mint& operator-=(Mint const& b) {
        value = ((value - b.value) % Modulus + Modulus) % Modulus;
        return *this;
    }
    Mint& operator*=(Mint const& b) {
        value = (int((value * 1LL * b.value) % Modulus) + Modulus) % Modulus;
        return *this;
    }

    static Mint mexp(Mint a, long long e) {
        Mint res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    static Mint inverse(Mint a) { return mexp(a, Modulus - 2); }
    Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend istream& operator>>(istream& istream, Mint& a) {
        long long v;
        istream >> v;
        a = v;
        return istream;
    }
    friend ostream& operator<<(ostream& ostream, Mint const& a) { return ostream << a.value; }
    friend bool operator==(Mint const& a, Mint const& b) { return a.value == b.value; }
    friend bool operator!=(Mint const& a, Mint const& b) { return a.value != b.value; }
};

using mint = Mint<MOD>;

struct Matrix {
    static ll const N = 13;
    mint mat[N][N];
    ll n, m;
    Matrix(ll _n = N, ll _m = N, ll val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    Matrix(const vector<vector<ll>>&& other) {
        n = ll(other.size());
        m = ll(other[0].size());
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = other[i][j];
    }
    Matrix& operator=(const vector<vector<ll>>&& other) {
        return *this = Matrix(forward<decltype(other)>(other));
    }
    mint* operator[](ll r) { return mat[r]; }
    const mint* operator[](ll r) const { return mat[r]; }
    static Matrix unit(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    friend Matrix operator*(const Matrix& A, const Matrix& B) {
        assert(A.m == B.n);
        Matrix res(A.n, B.m);
        for (ll i = 0; i < res.n; i++)
            for (ll j = 0; j < res.m; j++) {
                mint sum = 0;
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
    friend string to_string(const Matrix& a) {
        string res = "\n";
        for (ll i = 0; i < a.n; ++i) {
            res += '{';
            for (ll j = 0; j < a.m; ++j) {
                res += std::to_string(a.mat[i][j].value);
                if (j != a.m - 1) res += ", ";
            }
            res += "}\n";
        }
        res.append("\n");
        return res;
    }
    Matrix& operator*=(const Matrix& rhs) { return *this = *this * rhs; }
};

mint a[10], c[10];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    ll k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    int p, q, r;
    cin >> p >> q >> r;
    if (k < n) return cout << a[k] << '\n', 0;

    Matrix Base(n + 3, n + 3, 0), Transform(n + 3, 1);
    for (int i = 0; i < n; ++i) Base[0][i] = c[i];
    Base[0][n] = p, Base[0][n + 1] = q, Base[0][n + 2] = r;
    for (int i = 1; i < n; ++i) Base[i][i - 1] = 1;
    Base[n][n] = 1;                                                   // 1
    Base[n + 1][n] = Base[n + 1][n + 1] = 1;                          // i
    Base[n + 2][n] = Base[n + 2][n + 2] = 1, Base[n + 2][n + 1] = 2;  // i^2

    for (int i = 0; i < n; ++i) Transform[i][0] = a[n - 1 - i];
    Transform[n][0] = 1;
    Transform[n + 1][0] = n;
    Transform[n + 2][0] = n * n;

    auto res = power(Base, k - n + 1) * Transform;
    cout << res[0][0] << '\n';
}