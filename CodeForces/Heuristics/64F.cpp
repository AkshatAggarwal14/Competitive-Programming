#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
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
    ll n, r1, r2;
    cin >> n >> r1 >> r2, --r1, --r2;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n; ++i) {
        if (i == r1) continue;
        ll p;
        cin >> p, --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    vector<ll> ans(n, -1);
    auto dfs = [&](const auto &self, ll node, ll par) -> void {
        ans[node] = par;
        for (auto &child : g[node]) {
            if (child == par) continue;
            self(self, child, node);
        }
    };
    dfs(dfs, r2, -1);
    for (ll i = 0; i < n; ++i) {
        if (ans[i] == -1) continue;
        cout << ans[i] + 1 << ' ';
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
