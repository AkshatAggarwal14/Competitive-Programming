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

ll dp[105][6][6][6][6][6];

void test() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> c(n);
    vector<vector<ll>> a(n, vector<ll>(5));
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
        for (ll j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
        for (ll j = k; j < 5; ++j) {
            a[i][j] = 0;
        }
    }

    memset(dp, -1, sizeof(dp));

    // min price if {a, b, c, d, e} parameter value right now
    auto dfs = [&](const auto &self, ll index, vector<ll> ps) {
        bool all = true;
        for (ll i = 0; i < k; ++i) {
            if (ps[i] < p) all = false;
        }
        if (all) return 0LL;
        if (index == n) return INF;

        ll &ans = dp[index][ps[0]][ps[1]][ps[2]][ps[3]][ps[4]];
        if (ans != -1) return ans;

        // dont take current index
        ans = self(self, index + 1, ps);

        // take current
        for (int i = 0; i < k; ++i) {
            ps[i] += a[index][i];
            ps[i] = min(ps[i], p);
        }
        ans = min(ans, c[index] + self(self, index + 1, ps));

        return ans;
    };

    vector<ll> in(5, 0);
    ll ans = dfs(dfs, 0, in);
    if (ans == INF) ans = -1;
    cout << ans << '\n';
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
