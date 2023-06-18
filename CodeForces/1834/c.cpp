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
    string s, t;
    cin >> s >> t;
    ll cnt1 = 0, cnt2 = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] != t[i]) ++cnt1;
        if (s[n - 1 - i] != t[i]) ++cnt2;
    }
    ll ans = LLONG_MAX;
    if (cnt1 == 0) return void(cout << "0\n");
    if (cnt2 == 0) return void(cout << "2\n");
    // he converts T to S
    if (cnt1 % 2 == 0) {
        ans = min(ans, 2 * cnt1);
    } else {
        ans = min(ans, 2 * cnt1 - 1);
    }
    // he converts T to rev(S)
    if (cnt2 % 2 == 0) {
        ans = min(ans, 2 * cnt2 - 1);
    } else {
        ans = min(ans, 2 * cnt2);
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
