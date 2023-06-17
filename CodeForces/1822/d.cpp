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
    if (n == 1) return void(cout << "1\n");
    if (n & 1) return void(cout << "-1\n");
    vector<ll> a(n);
    ll i = 1, pos = 1;
    while (i < n) {
        a[i] = pos;
        pos += 2;
        i += 2;
    }
    i = n - 2, pos = 2;
    while (i >= 0) {
        a[i] = pos;
        pos += 2;
        i -= 2;
    }
    for (auto &x : a) cout << x << ' ';
    ll sum = 0;
    vector<ll> b(n), c(n);
    for (i = 0; i < n; ++i) {
        sum += a[i];
        b[i] = (sum % n + 1);
    }
    sort(b.begin(), b.end());
    iota(c.begin(), c.end(), 1);
    assert(b == c);
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
