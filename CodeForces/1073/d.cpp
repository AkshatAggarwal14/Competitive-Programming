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
    int n;
    ll T;
    cin >> n >> T;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll ans = 0, Min = *min_element(all(a));
    while (T >= Min) {
        ll count = 0, cost = 0, new_T = T;
        for (int i = 0; i < n; i++) {
            if (new_T >= a[i]) {
                new_T -= a[i];
                cost += a[i];
                count++;
            }
        }
        ans += count * (T / cost);
        T %= cost;
    }
    cout << ans << "\n";
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
