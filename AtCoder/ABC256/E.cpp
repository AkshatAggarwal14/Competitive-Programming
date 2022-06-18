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

enum states { NOT_VISITED,
              VISITING,
              VISITED };

void test() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<ll> val(n);
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u, --u;
        adj[i].push_back(u);
        // outdegree 1
        // functional graph
        // each component has exactly one cycle, THUS can also use DSU
    }
    for (ll &i : val) cin >> i;
    vector<states> vis(n, NOT_VISITED);
    ll ans = 0;
    vector<int> component;
    // Sum of minimum values in each cycle [SCC]
    function<void(int)> dfs = [&](int node) {
        vis[node] = VISITING, component.push_back(node);
        for (const int &child : adj[node]) {
            if (vis[child] == NOT_VISITED) {
                dfs(child);
            } else if (vis[child] == VISITING) {  // cycle found
                ll mn = INF;
                if (sz(component) > 1) {
                    while (component.back() != child) {
                        mn = min(mn, val[component.back()]);
                        component.pop_back();
                    }
                    mn = min(mn, val[child]);
                    component.clear();
                    ans += mn;
                }
            }
        }
        vis[node] = VISITED;
    };
    for (int i = 0; i < n; ++i) {
        if (vis[i] == VISITED) continue;
        component.clear();
        dfs(i);
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
