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
const ll MOD = 1e9 + 7;  // 998244353

const ll N = 2e5 + 10;

void test() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), pref(n + 1);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + (a[i] < i);
        if (a[i] < i && a[i] >= 1) {
            ans += pref[a[i] - 1];
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
