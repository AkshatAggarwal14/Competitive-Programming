#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e6;

vector<vector<ll>> dp(N + 1, vector<ll>(11));
// dp[len][last_digit] = distinct numbers of size len with last digit last_digit
void Solution() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int j = 1; j <= 9; ++j) ans = (ans + dp[n][j]) % MOD;
    cout << ans << '\n';
}

int main() {
    // dp[len][last_digit] = distinct numbers of size len with last digit last_digit
    for (ll j = 1; j <= 9; ++j) dp[1][j] = 1;
    for (ll i = 2; i <= N; ++i) {
        for (ll j = 1; j <= 9; ++j) {
            ll same = dp[i - 1][j];
            ll down = dp[i - 1][j - 1];
            ll up = dp[i - 1][j + 1];
            dp[i][j] = (same + down + up) % MOD;
        }
    }

    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}