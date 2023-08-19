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
    map<ll, ll> x, y, xmy, xpy;  // {store x}
    vector<array<ll, 2>> points(n);
    for (ll i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
        ++x[points[i][0]];
        ++y[points[i][1]];
        ++xpy[points[i][0] + points[i][1]];
        ++xmy[points[i][0] - points[i][1]];
    }

    ll ans = 0;
    // choose 2 out of all - 2 * C(N, 2)
    for (auto &[A, B] : x) ans += B * (B - 1);
    for (auto &[A, B] : y) ans += B * (B - 1);
    for (auto &[A, B] : xpy) ans += B * (B - 1);
    for (auto &[A, B] : xmy) ans += B * (B - 1);

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
