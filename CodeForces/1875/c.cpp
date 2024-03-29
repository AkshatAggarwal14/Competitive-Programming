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
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    ll g = gcd(n, m);
    n /= g, m /= g;
    if (__builtin_popcountll(m) != 1)
        return void(cout << "-1\n");
    m *= g, n *= g;
    // for terminating decimal, denominator must be 2^x * 5^y
    vector<ll> vals;
    // how many of each needed? 1, 1/2, 1/4 ...
    for (ll i = 0; i < 30; ++i) {
        ll times = n / m;
        vals.push_back(m * times);
        n -= times * m;
        n *= 2;
    }
    // 1/4 can be made using 1/2, so to minimise number of cuts
    vector<ll> suff(30);
    suff[0] = vals[0];
    suff[29] = vals[29];
    for (ll i = 28; i >= 1; --i) {
        suff[i] = (suff[i + 1] + 1) / 2 + vals[i];
    }
    ll ans = 0;
    // each 1/4,.. etc will take half cuts to create that exact amount
    for (ll i = 1; i < 30; ++i) {
        ans += suff[i] / 2;
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
