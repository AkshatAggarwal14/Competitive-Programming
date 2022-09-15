#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n + 1);
    for (int i = 2; i <= n; ++i) cin >> a[i];
    vector<ll> add(n + 1);
    for (ll i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        add[x] += y;
    }
    for (ll i = 2; i <= n; ++i) {
        if (t <= a[i]) return void(cout << "No\n");
        t -= a[i];
        t += add[i];
    }
    if (t <= 0) return void(cout << "No\n");
    cout << "Yes\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
