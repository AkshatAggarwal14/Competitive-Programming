#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto& container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T& a, U&& b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T& a, U&& b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

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
const ll MAXN = 3'00'000;
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

void Solution() {
    ll n, m, B;
    cin >> n >> m;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> B;
        if (B <= m) ++cnt;  // as no duplicate values
    }
    mint total = P(m, n);
    mint favourable(0), sign(1);
    for (ll i = 1; i <= cnt; ++i) {
        favourable += C(cnt, i) * P(m - i, n - i) * sign;
        sign *= -1;
    }
    mint ans = total - favourable;
    cout << ans << '\n';
}

int main() {
    init();
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