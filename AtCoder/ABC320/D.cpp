#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, pair<ll, ll>>>> g(n);
    vector<pair<ll, ll>> ans(n, {INF, INF});
    for (ll i = 0; i < m; ++i) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y, --a, --b;

        g[a].push_back({b, {x, y}});
        g[b].push_back({a, {-x, -y}});
    }

    ans[0] = {0, 0};
    vector<bool> vis(n, false);

    auto dfs = [&](const auto &self, ll node) -> void {
        vis[node] = true;
        for (auto &[child, it] : g[node]) {
            if (!vis[child]) {
                ans[child] = {ans[node].first + it.first, ans[node].second + it.second};
                self(self, child);
            }
        }
    };

    dfs(dfs, 0);

    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            cout << "undecidable\n";
        } else {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
