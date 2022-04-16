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
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    set<array<ll, 3>> used;
    vector<pair<ll, ll>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    if (k == 1) return void(cout << "Infinity\n");
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (j == i) continue;
            ll A = a[j].second - a[i].second;
            ll B = a[i].first - a[j].first;
            ll C = a[i].second * a[j].first - a[i].first * a[j].second;
            ll G = gcd(abs(A), gcd(abs(B), abs(C)));
            A /= G, B /= G, C /= G;
            if (used.count({A, B, C})) continue;
            used.insert({A, B, C});
            ll cnt = 0;
            for (ll K = 0; K < n; ++K)
                cnt += (A * a[K].first + B * a[K].second + C == 0);
            if (cnt >= k) ++ans;
        }
    }
    cout << ans / 2 << '\n';
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
