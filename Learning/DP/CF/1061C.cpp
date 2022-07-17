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
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &A : a) cin >> A;
    /*
    dp[i][j] = number of good subsequences of length j with first i elements
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= i; ++j) {
            // how many already have
            dp[i][j] = dp[i - 1][j];
            if (j > 0 && a[i - 1] % j == 0)
                // how many including this element
                dp[i][j] += dp[i - 1][j - 1];  // j must be factor of a[i]
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans += dp[n][i];
    cout << ans << '\n';

    ? as dp[i] only depends on dp[i - 1] we can optimise to 2 * n space
    ? as we see, dp[i][j] only changes when a[i] is divisible by j, otherwise it retains its old value
        Thus we can update 1D dp array in descending order using previous value, thus we sort factors in descending order.
    */

    auto add = [&](ll A, ll B) {
        return (A + B) % MOD;
    };
    vector<ll> dp(n + 1);
    // dp[i] = Number of good subsequences of length i
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                if (j <= n) t.push_back(j);
                if (a[i] / j != j && a[i] / j <= n) t.push_back(a[i] / j);
            }
        }
        sort(t.rbegin(), t.rend());
        for (auto &j : t) {
            dp[j] = add(dp[j], dp[j - 1]);
        }
        ++dp[1];
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans = add(ans, dp[i]);
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
