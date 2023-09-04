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
    ll n, x, y;
    cin >> x >> y >> n;
    vector<ll> a(n);
    a[n - 1] = y;
    ll d = 1;
    for (ll i = n - 2; i >= 0; --i) {
        a[i] = a[i + 1] - d;
        ++d;
    }
    if (a[0] < x) return void(cout << "-1\n");
    a[0] = x;
    for (auto &xx : a) cout << xx << ' ';
    cout << '\n';
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
