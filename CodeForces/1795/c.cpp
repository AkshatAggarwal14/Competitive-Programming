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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    // inc_range[i] stores number of times ith taster drinks a full cup of tea
    // inc_point[i] contains capacity he has to drink as leftover
    vector<ll> inc_range(n), inc_point(n), pref(n);
    pref[0] = b[0];
    for (ll i = 1; i < n; ++i) pref[i] = pref[i - 1] + b[i];
    for (ll i = 0; i < n; ++i) {
        // [i, n - 1] all tasters will get a chance to taste if remaining
        auto R = upper_bound(pref.begin() + i, pref.end(), a[i] + ((i > 0) ? pref[i - 1] : 0)) - pref.begin();
        ++inc_range[i];  // as in both cases
        if (R != n) {
            --inc_range[R];
            ll left = a[i];
            if (R > 0) left -= (pref[R - 1] - ((i > 0) ? pref[i - 1] : 0));
            inc_point[R] += left;
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (i > 0) inc_range[i] += inc_range[i - 1];
        cout << inc_point[i] + inc_range[i] * b[i] << ' ';
    }
    cout << '\n';
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
