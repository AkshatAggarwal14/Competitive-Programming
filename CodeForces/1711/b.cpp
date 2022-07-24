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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    vector<ll> deg(n);
    vector<array<ll, 2>> edges(m);
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        ++deg[u], ++deg[v];
        edges[i] = {u, v};
    }
    if (m % 2 == 0) return void(cout << "0\n");
    ll ans = INF;
    // remove 1
    for (ll i = 0; i < n; ++i) {
        if (deg[i] == 0) continue;
        ll left = m - deg[i];
        if (left % 2 == 0) {
            ans = min(ans, a[i]);
        }
    }
    // remove 2 - an edge
    for (ll i = 0; i < m; ++i) {
        auto [u, v] = edges[i];
        if (deg[u] % 2 == 0 && deg[v] % 2 == 0) {
            ans = min(ans, a[u] + a[v]);
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
