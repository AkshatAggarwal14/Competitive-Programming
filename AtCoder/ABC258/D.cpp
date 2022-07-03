#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = LLONG_MAX;  //! IMPORTANT
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) cin >> a[i] >> b[i];
    ll ans = INF, presum = 0, min_b = INF;
    for (ll i = 0; i < n && x > 0; ++i) {
        min_b = min(min_b, b[i]);
        presum += (a[i] + b[i]);
        ll already = i + 1;
        ll left = x - already;
        if (left < 0) break;
        ll time = min_b * left;
        ans = min(ans, presum + time);
    }
    cout << ans << '\n';
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
