#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }

const ll N = 5000;
const ll MOD = 998244353;
ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
array<ll, N + 1> fact;
array<ll, N + 1> inv;
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
ll inverse(ll a, ll m = MOD) { return modpow(a, m - 2, m); }  //Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
    inv[N] = inverse(fact[N]);
    for (ll i = N - 1; i >= 0; --i) inv[i] = mul(inv[i + 1], (i + 1));

    /*
    fact[0] = inv[0] = invf[0] = fact[1] = inv[1] = invf[1] = 1;
    for (ll i = 2; i <= N; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = M(-mul((MOD / i), inv[MOD % i]));
        invf[i] = mul(invf[i - 1], inv[i]);
    }
    */
}

ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv[b]), inv[a - b]);
}

void Solution() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
        pref[i] += ((i == 0) ? 0 : pref[i - 1]) + (s[i - 1] == '1');
    dbg(pref);
    ll p = 1;
    if (pref[n] >= k) {  // if this condition is true, then we can modify any cnt <= k
        for (ll L = 0; L < n; ++L) {
            for (ll R = L + 1; R < n; ++R) {
                ll cnt = pref[R + 1] - pref[L];
                if (cnt <= k) {
                    ll len = R - L + 1;
                    p += (C(len - 2, cnt - ((s[L] - '0') ^ 1) - ((s[R] - '0') ^ 1))) % MOD;
                }
            }
        }
    }
    cout << p % MOD << '\n';
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