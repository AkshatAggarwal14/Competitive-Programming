// ways to fill n x 3 grid with rectangles
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
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

int main() {
    int n;
    cin >> n;
    vector<vector<mint>> dp(n + 1, vector<mint>(4));
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
    /*
    dp[i][0]: fill ith level with 111
    dp[i][1]: fill ith level with 12
    dp[i][2]: fill ith level with 21
    dp[i][3]: fill ith level with 3

    111
    dp[i][0]:   1. dont extend any: dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]
                2. extend first:    dp[i - 1][0] + dp[i - 1][1]
                3. extend middle:   dp[i - 1][0]
                3. extend last:     dp[i - 1][0] + dp[i - 1][2]
                4. extend first 2:  dp[i - 1][2]
                5. extend last 2:   dp[i - 1][1]
                6. extend all 3:    dp[i - 1][0]

    12
    dp[i][1]:   1. dont extend any: dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i  - 1][3]
                2. extend 1:        dp[i - 1][0] + dp[i - 1][1]
                3. extend 2:        dp[i - 1][1]
                4. extend both:     dp[i - 1][1]

    21
    dp[i][2]:   1. dont extend any: dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i  - 1][3]
                2. extend 2:        dp[i - 1][2]
                3. extend 1:        dp[i - 1][0] + dp[i - 1][2]
                4. extend both:     dp[i - 1][2]

    3
    dp[i][3]:   1. dont extend any: dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i  - 1][3]
                2. extend 3:        dp[i - 1][3]

    Answer:     dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]
    */
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 5 * dp[i - 1][0] + 3 * dp[i - 1][1] + 3 * dp[i - 1][2] + dp[i - 1][3];
        dp[i][1] = 2 * dp[i - 1][0] + 4 * dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][2] = 2 * dp[i - 1][0] + dp[i - 1][1] + 4 * dp[i - 1][2] + dp[i - 1][3];
        dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + 2 * dp[i - 1][3];
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] << '\n';
}