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
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    // ai = aj * ak
    ll n;
    cin >> n;
    vector<ll> a(n), cnt(N, 0);
    for (ll i = 0; i < n; i++) cin >> a[i], ++cnt[a[i]];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                if (cnt[j] && cnt[a[i] / j]) {
                    ll t = cnt[j] * cnt[a[i] / j];
                    if (j != a[i] / j) t *= 2;  // change order
                    ans += t;
                }
            }
        }
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
