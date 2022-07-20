#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
template <int Modulus = MOD>
struct Mint {
    int value;
    Mint(ll v = 0) {
        value = int(v % Modulus);
        if (value < 0) value += Modulus;
    }
    friend ll& normalize(ll& x) {
        while (x >= Modulus) x -= Modulus;
        while (x < 0) x += Modulus;
    }
    friend string to_string(const Mint& a) { return to_string(a.value); }
    Mint& operator+=(Mint const& b) {
        value += b.value;
        normalize(value);
        return *this;
    }
    Mint& operator-=(Mint const& b) {
        value -= b.value;
        normalize(value);
        return *this;
    }
    Mint& operator*=(Mint const& b) {
        value = int((value * 1LL * b.value) % Modulus);
        normalize(value);
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
