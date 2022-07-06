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
const ll MAXN = 1'00'000;
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
    int n;
    cin >> n;
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; ++i) cin >> a[i], pos[a[i]] = i;
    int l = pos[0], r = pos[0];
    int locked = 1;
    int unlocked = 0;
    int cur = 1;
    mint ans = 1;
    while (cur < n) {
        if (l <= pos[cur] && pos[cur] <= r) {
            unlocked++;
        } else {
            // permute unlocked in range
            ans *= P(r - l + 1 - locked, unlocked);
            // all permuted get locked
            // this one never visited yet, gets locked too
            locked += unlocked + 1;
            unlocked = 0;
            r = max(r, pos[cur]);
            l = min(l, pos[cur]);
        }
        cur++;
    }
    ans *= P(r - l + 1 - locked, unlocked);
    cout << ans << "\n";
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
