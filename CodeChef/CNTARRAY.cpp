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

/*
3 4
5 1 2

Total = 4*3*2 = 24
Fix 1 at 2nd pos = 3*2*1 = 6
Fix 2 at 3rd pos = 3*2*1 = 6
Fix 1 and 2 at 2nd and 3rd resp = 2*1 = 2

Answer = 24 - 6 - 6 + 2 = 14
*/

const ll N = 3'00'000;
const ll MOD = 1e9 + 7;  // 998244353;
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

ll P(ll a, ll b) {
    if (a < b) return 0;
    return mul(fact[a], inv[a - b]);
}

/*
    ans = total - favourable ways
    favourable ways = permutations with fixed a[i] = b[i]

    now as in venn diagrams
    A U B U C = A + B + C - A ∩ B - B ∩ C - A ∩ C + A U B U C
    ! alternating sign of term
    favourable = region1 * 3 - common_region2 * 3 + common_region3
    favourable = C(cnt, 1) * P(m - 1, n - 1) - C(cnt, 2) * P(m - 2, n - 2) + ...

    total = M!/N! -> P(M, N)
    ans = total - favourable
*/

/*
    ! Better explanation
    first count fixed elements >=1 and <=  m -> cnt
    favourable ways = (choosing which 1 element to fix)* (number of perms with 1 element fixed) - (choosing which 2 elements to fix) * (number of perms with 2 elements fixed) + ... 
    favourable = C(cnt, 1) * P(m - 1, n - 1) - C(cnt, 2) * P(m - 2, n - 2) + ...
    favourable = [sum from i = 1 to cnt] (C(cnt, i) * P(m - i, n - i) * (-1)^(i+1))
    total = P(m , n)
    ans = total - favourable
*/

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n);
    ll cnt = 0;  // always less than n
    for (ll &x : b) {
        cin >> x;
        if (x >= 1 && x <= m) ++cnt;  // no duplicate values
    }
    // count all values already set, which we need to exclude
    ll total = P(m, n);  // total ways = m!/n!
    ll ways = 0, term = 1;
    for (ll i = 1; i <= cnt; ++i) {
        ways = add(ways, mul(mul(C(cnt, i), P(m - i, n - i)), term));
        term *= -1;
    }
    cout << M(total - ways) << '\n';
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