#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 998244353;

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> mx(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i; j <= n; j += i) {
            mx[i] = max(mx[i], a[j]);
        }
    }

    sort(mx.begin(), mx.end());
    ll ans = 0;
    for (ll i = n; i >= 1; --i) {
        // less answer wale saare subsets
        ans += (power(2, i - 1) * mx[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
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
