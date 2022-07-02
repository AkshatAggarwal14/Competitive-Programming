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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    vector<ll> pref(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += a[i];
        pref[i] = sum;
        if (i > 0 && pref[i - 1] > pref[i]) pref[i] = pref[i - 1];
    }
    while (m--) {
        ll x;
        cin >> x;
        ll trips = 0;
        if (sum > 0 && x > pref[n - 1])
            trips = (x - pref[n - 1] + sum - 1) / sum;
        ll nx = x - sum * trips;
        // find first position where pref[i] >= nx
        ll L = 0, R = n - 1;
        --L, ++R;
        ll ans = -1;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (pref[M] >= nx) {
                R = M;
                ans = M;
            } else {
                L = M;
            }
        }
        ans += n * trips;
        cout << ans << ' ';
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
