#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

void Solution() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    vector<ll> a(n), deg(n, 0);
    for (ll &A : a) cin >> A;
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        --u, --v;
        ++deg[u], ++deg[v];
        g[u].push_back(v), g[v].push_back(u);
    }

    ll ans = 0;
    set<ll> in;
    for (ll i = 0; i <= n; ++i) in.insert(i);
    vector<ll> cnt(n + 10, 0);

    auto dfs = [&](const auto &self, ll node, ll parent = -1) -> void {
        // add element to cnt and remove from set
        ++cnt[a[node]];
        if (cnt[a[node]] == 1) in.erase(a[node]);

        if (deg[node] == 1) {
            ans = max(ans, *in.begin());
        }

        // process subtree
        for (auto &child : g[node]) {
            if (child == parent) continue;
            self(self, child, node);
        }

        // remove element from cnt and add to in
        --cnt[a[node]];
        if (cnt[a[node]] == 0) in.insert(a[node]);
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
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}