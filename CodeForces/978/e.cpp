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
    ll n, w;
    cin >> n >> w;
    // 0 <= initial + pre[i] <= w
    // -pre[i] <= initial <= w - pre[i]
    // initial >= max(0, -pre[i])
    // initial <= min(w, w - pre[i])
    ll sum = 0;
    ll l = 0, r = w;
    for (ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        sum += num;
        l = max({l, 0LL, -sum});
        r = min({r, w, w - sum});
    }
    cout << max(r - l + 1, 0LL) << '\n';
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
