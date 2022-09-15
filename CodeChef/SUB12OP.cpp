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
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    for (ll i = n - 1; i > 0; --i) {
        if (a[i] > 0) {
            ll times = a[i] / 2;
            a[i - 1] -= times;
            a[i] -= 2 * times;
        }
    }
    for (ll i = n - 1; i > 0; --i) {
        if (a[i] == 1 && a[i - 1] > 0) {
            a[i] = -1;
            --a[i - 1];
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) ans += abs(a[i]);
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
