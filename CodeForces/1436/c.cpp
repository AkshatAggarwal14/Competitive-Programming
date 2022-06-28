#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto& container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

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

    Mint mexp(Mint a, long long e) {
        Mint res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    Mint inverse(Mint a) { return mexp(a, Modulus - 2); }
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
const ll MAXN = 1'010;
vector<mint> fact(MAXN, 1), invf(MAXN, 1);

void init() {
    for (ll i = 2; i < MAXN; i++) fact[i] = fact[i - 1] * i;
    invf[MAXN - 1] = 1 / fact[MAXN - 1];
    for (ll i = MAXN - 2; i >= 2; i--) invf[i] = invf[i + 1] * (i + 1);
}

mint C(ll a, ll b) {
    if (a < b) return mint();
    return fact[a] * invf[b] * invf[a - b];
}

mint P(ll a, ll b) {
    if (a < b) return mint();
    return fact[a] * invf[a - b];
}

void test() {
    ll n, x, pos;
    cin >> n >> x >> pos;
    ll less = 0, more = 0;
    ll l = 0, r = n;
    while (l < r) {
        ll m = (l + r) / 2;
        if (m == pos) {
            l = m + 1;
        } else if (m < pos) {
            l = m + 1;
            ++less;
        } else {
            r = m;
            ++more;
        }
    }
    ll larger = n - x, smaller = x - 1;
    mint ans = 1;
    ans *= C(larger, more) * fact[more];   // selecting and arranging more
    ans *= C(smaller, less) * fact[less];  // selecting and arranging less
    ans *= fact[n - (1 + more + less)];    // arranging remaining
    cout << ans << '\n';
}

int32_t main() {
    init();
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE* in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE* out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
