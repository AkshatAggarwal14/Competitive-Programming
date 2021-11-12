#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

template <uint64_t mod>
class Modular {
   private:
    uint64_t n;

   public:
    Modular(int64_t _n = 0) : n((_n >= 0 ? _n : mod - (-_n) % mod) % mod) {}
    uint64_t get() const { return n; }
    bool operator==(const Modular &o) const { return n == o.n; }
    bool operator!=(const Modular &o) const { return n != o.n; }
    Modular &operator+=(const Modular &o) {
        n += o.n;
        n = (n < mod ? n : n - mod);
        return *this;
    }
    Modular &operator-=(const Modular &o) {
        n += mod - o.n;
        n = (n < mod ? n : n - mod);
        return *this;
    }
    Modular &operator*=(const Modular &o) {
        n = uint64_t(n) * o.n % mod;
        return *this;
    }
    Modular &operator/=(const Modular &o) { return (*this) *= o.inv(); }
    Modular operator+(const Modular &o) const { return Modular(*this) += o; }
    Modular operator-(const Modular &o) const { return Modular(*this) -= o; }
    Modular operator*(const Modular &o) const { return Modular(*this) *= o; }
    Modular operator/(const Modular &o) const { return Modular(*this) /= o; }
    Modular pow(uint64_t b) const {
        Modular ans(1), m = Modular(*this);
        while (b) {
            if (b & 1) {
                ans *= m;
            }
            m *= m;
            b >>= 1;
        }
        return ans;
    }
    Modular inv() const {
        int32_t a = n, b = mod, u = 0, v = 1;
        while (a) {
            int32_t t = b / a;
            b -= t * a;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        assert(b == 1);
        return Modular(u);
    }
    friend string to_string(const Modular &m) {
        return to_string(m.get());
    }
};
using Mint = Modular<int(1e9 + 7)>;

void Solution() {
    int n;
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; ++i) cin >> P[i];
    vector<Mint> moves(n + 1);
    Mint steps = 0;
    for (int ctr = 1; ctr <= n; ++ctr) {
        int p = P[ctr];
        for (int i = p; i < ctr; ++i) moves[ctr] += moves[i];
        moves[ctr] += Mint(1);        // to go back
        moves[ctr] += Mint(ctr - p);  // to come forward
        steps += 1;
    }
    for (int i = 1; i <= n; ++i) steps += moves[i];
    cout << steps.get() << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}