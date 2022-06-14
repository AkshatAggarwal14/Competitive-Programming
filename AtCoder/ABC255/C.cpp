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

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    if (d == 0) return void(cout << abs(x - a) << '\n');
    ll first = a, last = a + (n - 1) * d;
    ll ans = min({abs(x - last), abs(x - first)});
    if (x >= first && x <= last)
        ans = min(ans,
                  min((abs(x - a)) % abs(d),
                      (abs(d) - (abs(x - a)) % abs(d))));
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
