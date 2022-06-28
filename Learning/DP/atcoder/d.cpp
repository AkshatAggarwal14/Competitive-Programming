#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    for (ll i = 0; i < n; ++i) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n, vector<ll>(W + 1, -1));
    function<ll(ll, ll)> dfs = [&](ll id, ll wt) {
        if (wt == 0 || id < 0) return 0LL;
        ll &ans = dp[id][wt];
        if (ans != -1) return ans;
        ans = dfs(id - 1, wt);
        if (wt >= w[id]) {
            ans = max(ans, dfs(id - 1, wt - w[id]) + v[id]);
        }
        return ans;
    };
    cout << dfs(n - 1, W) << '\n';
    return 0;
}
