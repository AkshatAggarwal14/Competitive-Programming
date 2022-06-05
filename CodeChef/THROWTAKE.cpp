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

void test() {
    ll n;
    cin >> n;
    vector<ll> C(n);
    for (auto &it : C) cin >> it;
    vector<ll> V;
    for (ll i = 0, num; i < n; i++) {
        cin >> num;
        if (C[i] % 2 == 1) V.push_back(num);
    }
    n = sz(V);
    vector<vector<ll>> dp(2, vector<ll>(n, -1));
    function<ll(ll, ll)> dfs = [&](ll pos, ll player) -> ll {
        if (pos == n) return 0;
        ll &ans = dp[player][pos];
        if (ans != -1) return ans;
        ans = dfs(pos + 1, player);
        if (player == 0)  // alice is trying to maximise her value
            ans = max(ans, dfs(pos + 1, 1) + V[pos]);
        else  // bob is trying to minimize alice's value
            ans = min(ans, dfs(pos + 1, 0) - V[pos]);
        return ans;
    };
    cout << dfs(0, 0) << '\n';
    dbg(dp);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
