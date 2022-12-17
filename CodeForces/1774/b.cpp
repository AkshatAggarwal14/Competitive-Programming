#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for (auto &x : a) cin >> x;
    if (k > m) return void(cout << "NO\n");
    if (n % k == 0) {
        for (int i = 0; i < m; ++i) {
            if (a[i] > n / k) return void(cout << "NO\n");
        }
    } else {
        ll cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (a[i] > n / k + 1) return void(cout << "NO\n");
            if (a[i] == n / k + 1) ++cnt;
        }
        if (cnt > n % k) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
