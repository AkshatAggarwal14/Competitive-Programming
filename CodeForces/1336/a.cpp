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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // when you choose some node, you subtract 1 from answer of all in subtree
    // So, sort by d[i] - subtree[i] and choose k largest
    vector<ll> ans(n, 0);
    function<ll(ll, ll, ll)> dfs = [&](ll node, ll par, ll level) {
        ans[node] = level;
        ll sub = 0;
        for (auto &child : g[node]) {
            if (child != par) {
                sub += 1 + dfs(child, node, level + 1);
            }
        }
        ans[node] -= sub;
        return sub;
    };

    dfs(0, -1, 0);
    sort(ans.rbegin(), ans.rend());
    cout << accumulate(ans.begin(), ans.begin() + k, 0LL) << '\n';
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
