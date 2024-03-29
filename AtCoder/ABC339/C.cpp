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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> pref(n);
    pref[0] = a[0];
    for (ll i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    ll mn = INF;
    for (ll i = 0; i < n; ++i) {
        mn = min(mn, pref[i]);
    }

    ll ans = pref[n - 1];
    dbg(mn, ans);

    if (mn < 0) {
        ans -= mn;
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
