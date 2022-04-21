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
    vector<ll> pref(n, 0), suff(n, 0);
    for (ll &A : a) cin >> A;
    pref[0] = a[0], suff[n - 1] = a[n - 1];
    for (ll i = 1; i < n; ++i) pref[i] = pref[i - 1] + a[i];
    for (ll i = n - 2; i >= 0; --i) suff[i] = suff[i + 1] + a[i];
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll front = pref[i];
        ll L = i + 1, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (suff[M] >= front) {
                L = M;
            } else {
                R = M;
            }
        }
        if (suff[L] == pref[i] && i < L) ans = max(ans, (i + 1) + (n - L));
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
