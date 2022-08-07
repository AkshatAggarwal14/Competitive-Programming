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
    ll n;
    cin >> n;
    ll mx_x = 0, mx_y = 0, mn_x = 0, mn_y = 0;
    for (ll i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        mn_x = min(mn_x, x);
        mx_x = max(mx_x, x);
        mn_y = min(mn_y, y);
        mx_y = max(mx_y, y);
    }
    cout << 2 * (mx_x - mn_x + mx_y - mn_y) << '\n';
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
