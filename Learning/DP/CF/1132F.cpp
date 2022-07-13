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
    // https://codeforces.com/contest/1132/problem/F
    ll n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    function<ll(ll, ll)> dfs = [&](ll l, ll r) {
        if (l > r) return 0LL;
        if (l == r) return 1LL;
        ll &ans = dp[l][r];
        if (ans != -1) return ans;

        if (l < n - 1 && s[l] == s[l + 1])
            ans = dfs(l + 1, r);
        else
            ans = 1 + dfs(l + 1, r);

        for (ll i = l + 1; i <= r; ++i) {
            if (s[l] == s[i]) {  // l_th letter deleted with i_th
                ans = min(ans, dfs(l + 1, i - 1) + dfs(i, r));
            }
        }
        return ans;
    };

    cout << dfs(0, n - 1) << '\n';
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
