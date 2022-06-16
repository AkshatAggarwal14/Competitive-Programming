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
    for (ll &A : a) cin >> A;
    ll res = INF;
    for (ll skip = 0; skip < n; ++skip) {
        vector<ll> b(n, 0);
        ll ans = 0;
        for (ll i = skip - 1; i >= 0; --i) {
            if (b[i] >= b[i + 1]) {
                ll dec = abs(b[i] - b[i + 1]) / a[i];
                if (b[i] - dec * a[i] >= b[i + 1]) ++dec;
                ans += dec;
                b[i] = b[i] - dec * a[i];
            }
        }
        for (ll i = skip + 1; i < n; ++i) {
            if (b[i] <= b[i - 1]) {
                ll inc = abs(b[i - 1] - b[i]) / a[i];
                if (b[i] + inc * a[i] <= b[i - 1]) ++inc;
                ans += inc;
                b[i] = b[i] + inc * a[i];
            }
        }
        res = min(res, ans);
    }
    cout << res << '\n';
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
