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
    string s;
    cin >> n >> s;
    ll ans = 0;
    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; ++i) pref[i] = pref[i - 1] + ((s[i - 1] == '+') ? 1 : -1);
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            ll diff = pref[j] - pref[i];
            if (diff <= 0 && diff % 3 == 0) {
                ++ans;
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
