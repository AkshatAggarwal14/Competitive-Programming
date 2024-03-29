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
    string s;
    cin >> n >> s;

    ll mx = (n & 1), mn = 0;
    for (ll i = 0; i < n / 2; ++i) {
        if (s[i] == s[n - 1 - i]) {
            mx += 2;
        } else {
            ++mx, ++mn;
        }
    }

    string ans(n + 1, '0');
    for (ll i = mn; i <= mx; i += ((n & 1) ? 1 : 2))
        ans[i] = '1';
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
