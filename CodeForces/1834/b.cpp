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
    string L, R;
    cin >> L >> R;
    reverse(L.begin(), L.end());
    while (L.size() < R.size()) L.push_back('0');
    reverse(L.begin(), L.end());
    ll n = L.size();
    ll ans = 0, i = 0;
    while (i < n && L[i] == R[i]) {
        ++i;
    }
    if (i < n) {
        ans += R[i] - L[i];
        for (ll j = i + 1; j < n; ++j) ans += 9;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
