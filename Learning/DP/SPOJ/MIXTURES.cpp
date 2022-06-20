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

void test(ll n) {
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<ll> pref(n + 1);
    for (ll i = 0; i < n; ++i) pref[i + 1] = pref[i] + arr[i];
    auto get = [&](ll l, ll r) {
        if (l > r) return 0LL;
        return pref[r + 1] - pref[l];
    };
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    function<ll(ll, ll)> dfs = [&](ll l, ll r) {
        if (l >= r) return 0LL;
        ll &ans = dp[l][r];
        if (ans != -1) return ans;
        ans = INF;
        for (ll k = l; k < r; ++k) {
            ll sumL = get(l, k) % 100;
            ll sumR = get(k + 1, r) % 100;
            ans = min(ans, dfs(l, k) + dfs(k + 1, r) + sumL * sumR);
        }
        return ans;
    };
    cout << dfs(0, n - 1) << '\n';
}

int32_t main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ll n;
    while (cin >> n) {
        test(n);
    }
    return 0;
}
