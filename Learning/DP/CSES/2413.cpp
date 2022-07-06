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
const ll N = 1e6 + 5;
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

vector<vector<mint>> dp;
void fill() {
    /*
    STATES:
        dp[i][0] = ways to fill [0..i]th position of tower where ith step has 2 tiles of 1 width
        dp[i][1] = ways to fill [0..i]th position of tower where ith step has 1 tile of 2 width

    ans: dp[n - 1][0] + dp[n - 1][1]

    TRANSITIONS:
        dp[i][0]:
            1. do not extend any tile -> dp[i - 1][0] + dp[i - 1][1]
            2. extend both -> dp[i - 1][0]
            3. extend one of these -> 2 * dp[i - 1][0]

        dp[i][1]:
            1. do not extend any tile -> dp[i - 1][0] + dp[i - 1][1]
            2. extend both -> dp[i - 1][1]
    */
    dp.resize(N, vector<mint>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) + (dp[i - 1][0]) + (2 * dp[i - 1][0]);
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) + (dp[i - 1][1]);
    }
}

int32_t main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        int n;
        cin >> n;
        cout << dp[n - 1][0] + dp[n - 1][1] << '\n';
    }
    return 0;
}
