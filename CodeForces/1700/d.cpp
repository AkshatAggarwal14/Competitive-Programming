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
    ll n;
    cin >> n;
    vector<ll> a(n);
    // to fill ith lock as fast as possible, open all pipes <= i
    // so find maximum among all minimum times for each lock
    ll sum = 0, mx = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        ll pipes = i + 1;
        ll min_time = (sum + pipes - 1) / pipes;  // ceil(sum / pipes)
        mx = max(mx, min_time);
    }
    ll q;
    cin >> q;
    // if there are p pipes open, p is water flow per second, so it takes ceil(capacity / p) seconds to fill
    while (q--) {
        ll t;
        cin >> t;
        ll pipes = (sum + t - 1) / t;  // ceil(sum / t) <- can be used to find pipes
        if (t < mx) {
            cout << "-1\n";
        } else {
            cout << pipes << '\n';
        }
    }
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
