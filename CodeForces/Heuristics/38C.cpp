#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto& container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T& a, U&& b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T& a, U&& b) { return a < b ? a = std::forward<U>(b), true : false; }

//https://github.com/NavneelSinghal/CodeBook/blob/master/math/mint.cpp
template <uint32_t Modulus>
class Modular {
    using M = Modular;

   public:
    static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
    static constexpr int modulus() { return Modulus; }
    static M raw(uint32_t v) { return *reinterpret_cast<M*>(&v); }
    Modular() : v_(0) {}
    Modular(int64_t v) : v_((v %= Modulus) < 0 ? uint32_t(v) + Modulus : uint32_t(v)) {}
    template <class T>
    explicit operator T() const {
        return v_;
    }
    M& operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
    M& operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
    M operator+() const { return *this; }
    M operator-() const { return raw(v_ ? Modulus - v_ : 0); }
    M& operator*=(M o) { return v_ = uint32_t(uint64_t(v_) * o.v_ % Modulus), *this; }
    M& operator/=(M o) {
        auto [inv, gcd] = extgcd(o.v_, Modulus);
        assert(gcd == 1);
        return *this *= inv;
    }
    M& operator+=(M o) {
        return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
    }
    M& operator-=(M o) {
        return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
    }
    friend M operator++(M& a, int) { return std::exchange(a, ++M(a)); }
    friend M operator--(M& a, int) { return std::exchange(a, --M(a)); }
    friend M operator*(M a, M b) { return a *= b; }
    friend M operator/(M a, M b) { return a /= b; }
    friend M operator+(M a, M b) { return a += b; }
    friend M operator-(M a, M b) { return a -= b; }
    friend std::istream& operator>>(std::istream& is, M& x) {
        int64_t v;
        return is >> v, x = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, M x) {
        return os << x.v_;
    }
    friend bool operator==(M a, M b) { return a.v_ == b.v_; }
    friend bool operator!=(M a, M b) { return a.v_ != b.v_; }
    friend string to_string(Modular<Modulus> n) { return to_string(n.v_); }

   private:
    static std::array<int, 2> extgcd(int a, int b) {
        std::array x{1, 0};
        while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
        return {x[0], a};
    }
    uint32_t v_;
};
constexpr long long md = 1e9 + 7;
using mint = Modular<md>;

void Solution() {
    int n;
    vector<mint> a(5);
    for (int i = 0; i < 5; ++i) cin >> a[i];
    cin >> n;
    vector<mint> pop(max(n, 4), 0);
    pop[0] = 1, pop[1] = 2, pop[2] = 3, pop[3] = 4;
    dbg(pop);
    for (int i = 4; i < n; ++i) {
        pop[i] = a[0] * pop[i - 1] + a[1] * pop[i - 2] + a[2] * pop[i - 3] + a[3] * pop[i - 4] + a[4];
    }
    cout << pop[n - 1] << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}