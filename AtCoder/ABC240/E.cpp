#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> deg(n, 0);
    vector<vector<ll>> g(n);
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v), g[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    vector<ll> cnt(n, 0);
    vector<pair<ll, ll>> ans(n);
    auto dfs = [&](const auto &self, ll node, ll par = -1) -> void {
        cnt[node] = (deg[node] == 1);
        for (auto &child : g[node]) {
            if (child == par) continue;
            self(self, child, node);    
            cnt[node] += cnt[child];
        }
    };
    dfs(dfs, 0);
    ans[0] = {1, cnt[0] - (deg[0] == 1)};
    auto dfs2 = [&](const auto &self, ll node, ll par, ll l) -> void {
        ll left = l;
        for (ll &child : g[node]) {
            if (child != par) {
                ans[child] = {left, left + cnt[child] - 1};
                self(self, child, node, left);
                left = left + cnt[child];
            }
        }
    };
    dfs2(dfs2, 0, -1, 1);
    for (ll i = 0; i < n; ++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}