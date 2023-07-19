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
    ll n, d, h;
    cin >> n >> d >> h;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (i < n - 1 && a[i + 1] - a[i] <= h) {
            // trapezium

            // (sum of sides) * h / 2
            double s1 = double(d);
            double s2 = double(d * (h - (a[i + 1] - a[i]))) / double(h);
            ans += (s1 + s2) * double(a[i + 1] - a[i]) / 2.0;
        } else {
            // triangle
            ans += double(d * h) / 2.0;
        }
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
