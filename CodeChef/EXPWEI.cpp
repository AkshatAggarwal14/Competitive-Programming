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

#define NCR
const ll N = 5;
ll MOD = 998244353;
ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
ll fact[N];
ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}
// a**(p - 1) % p == 1
// a*(a**(p - 2)) % p == 1
// a**(p - 2) % p == 1 / a
ll inv(ll a, ll m) { return modpow(a, m - 2, m); }  //Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}
ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv(fact[b], MOD)), inv(fact[a - b], MOD));
}

void Solution() {
    // n*(n+1)^2/4
    ll n;
    cin >> n;
    cout << mul(n, mul(n + 1, mul(n + 1, inv(4, MOD)))) << '\n';
}

// clang-format off
int main() {
    init();
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