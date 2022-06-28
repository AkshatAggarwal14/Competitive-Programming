/**
 *    author:  master._.mind
 *    created: 2022.06.28 16:17:38
 **/

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

void test() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    // for current move, for some floor i, you are checking what range from previous move can bring us to i, and you add that to get current move answer
    // dp[i][j] = ways to reach floor i on move j.

    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));
    dp[a][0] = 1;
    for (int j = 1; j <= k; j++) {
        vector<mint> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + dp[i][j - 1];
        for (int i = 1; i <= n; i++) {
            // find range from which we can reach current floor from last move
            if (i < b) {
                // range {mx, 1} - dp[i][j - 1]
                // dp[i][j - 1] subtracted as cant reach given floor from same
                dp[i][j] = pref[(b + i - 1) / 2] - dp[i][j - 1];
            } else if (i > b) {
                // range {mn, n} - dp[i][j - 1]
                dp[i][j] = pref[n] - pref[(b + i) / 2] - dp[i][j - 1];
            }
        }
    }

    mint sum = 0;
    for (int i = 1; i <= n; i++) sum += dp[i][k];
    // answer is ways to reach all floors after k moves
    cout << sum << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
