#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;

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
ll inverse(ll a, ll m = MOD) { return modpow(a, m - 2, m); }  // Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
    inv[N] = inverse(fact[N]);
    for (ll i = N - 1; i >= 0; --i) inv[i] = mul(inv[i + 1], (i + 1));
}

ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv[b]), inv[a - b]);
}

void test() {
    init();

    int a, b, n;
    cin >> a >> b >> n;

    auto isGood = [&](ll num) {
        ll t = num;
        while (t) {
            if (t % 10 != a and t % 10 != b)
                return 0;
            t /= 10;
        }

        return 1;
    };

    ll ans = 0;
    for (int occ = 0; occ <= n; ++occ) {
        ll sum = occ * a + (n - occ) * b;
        if (isGood(sum)) {
            ans = add(ans, C(n, occ));
        }
    }

    cout << ans << '\n';

    // int dp[N][2][2];
    // string L(n, '0'), R(n, '9');
    // L[0] = '1';

    // memset(dp, -1, sizeof(dp));

    // auto dfs = [&](const auto &self, int i, bool leftTight, bool rightTight, int sum) {
    //     if (i == n) {
    //         return isGood(sum);
    //     }

    //     int &ans = dp[i][leftTight][rightTight][sum];
    //     if (ans != -1) return ans;
    //     ans = 0;

    //     int lb = 0, ub = 9;
    //     if (leftTight) lb = int(L[i] - '0');
    //     if (rightTight) ub = int(R[i] - '0');

    //     if (a >= lb and a <= ub) {
    //         ans += self(self, i + 1, leftTight && (a == lb), rightTight && (a == ub), sum + a);
    //         ans %= MOD;
    //     }
    //     if (b >= lb and b <= ub) {
    //         ans += self(self, i + 1, leftTight && (b == lb), rightTight && (b == ub), sum + b);
    //         ans %= MOD;
    //     }

    //     return ans;
    // };

    // cout << dfs(dfs, 0, true, true, 0) << '\n';
}

int32_t
main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
