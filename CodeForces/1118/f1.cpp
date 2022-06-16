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
    vector<ll> col(n), subtree_red(n), subtree_blue(n);
    for (ll &c : col) cin >> c;
    vector<vector<ll>> g(n);
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v), g[v].push_back(u);
    }
    ll blue = count(all(col), 2), red = count(all(col), 1);
    ll ans = 0;
    auto dfs = [&](const auto &self, ll node, ll par = -1) -> void {
        subtree_red[node] = (col[node] == 1);
        subtree_blue[node] = (col[node] == 2);
        for (auto &child : g[node]) {
            if (child == par) continue;
            self(self, child, node);
            if ((subtree_blue[child] == blue && subtree_red[child] == 0) ||
                (subtree_red[child] == red && subtree_blue[child] == 0))
                ++ans;
            subtree_blue[node] += subtree_blue[child];
            subtree_red[node] += subtree_red[child];
        }
    };
    dfs(dfs, 0);
    cout << ans << '\n';
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