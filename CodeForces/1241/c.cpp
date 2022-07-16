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
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) cin >> p[i], p[i] /= 100;
    ll x, a, y, b;
    cin >> x >> a >> y >> b;
    ll k;
    cin >> k;
    vector<ll> contri(n);
    for (ll i = 0; i < n; ++i) {
        if ((i + 1) % a == 0) contri[i] += x;
        if ((i + 1) % b == 0) contri[i] += y;
    }
    sort(all(p), greater<ll>());
    auto can = [&](ll id) {
        assert(id >= 0 && id <= n);
        vector<ll> n_contri;
        for (ll i = 0; i <= id; ++i)
            n_contri.push_back(contri[i]);
        sort(all(n_contri), greater<ll>());
        ll ans = 0;
        for (ll i = 0; i <= id; ++i) ans += n_contri[i] * p[i];
        return ans >= k;
    };

    ll L = 1, R = n;
    --L, ++R;
    ll ans = -1;
    while (R > L + 1) {
        ll M = (L + R) / 2;
        if (can(M - 1)) {
            ans = M;
            R = M;
        } else {
            L = M;
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
