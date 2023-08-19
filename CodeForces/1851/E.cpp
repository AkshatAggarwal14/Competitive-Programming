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
    vector<ll> cost(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> cost[i];

    while (m--) {
        ll num;
        cin >> num;
        cost[num] = 0;
    }

    vector<vector<ll>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        ll len;
        cin >> len;
        while (len--) {
            ll num;
            cin >> num;
            g[i].push_back(num);
        }
    }

    vector<ll> dp(n + 1, INF);
    function<ll(ll)> dfs = [&](ll node) {
        ll &ans = dp[node];
        if (ans != INF) return ans;

        if (g[node].empty()) return ans = cost[node];

        ll sum = 0;
        for (auto &child : g[node]) {
            sum += dfs(child);
        }
        return ans = min(sum, cost[node]);
    };

    for (int i = 1; i <= n; ++i) cout << dfs(i) << ' ';

    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
