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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    /*
    dp[i] -> maximum possible sum of subarray ending at ith element
    Here we have a choice to multiply by x, if already we have not multiplied a subarray
    Now to know if x is usable we can use 2 states, x is usable if state 1, else state is 0

    if x is usable, we can multiply ith element by x, but inside an effected subarray also, x is usable, thus we can be at a middle index of effected subarray
    Thus we can subdivide x is usable state into 2 parts:   1. In use
                                                            2. Not in use
    */

    vector<vector<ll>> dp(n, vector<ll>(3, -1));
    // or could have used dp[n][2][2];

    //? States
    // dp[i][0] => ending at ith element but the subarray is already used [not usable]
    // dp[i][1] => ending at ith element but subarray is usable but not currently in use, can be started [not in use]
    // dp[i][2] => ending at ith element but subarray is being used [in use]
    //? Recurrences
    // dp[i][0] =>  1. a[i]
    //              2. a[i] + dp[i - 1][0] {Stopped using it way before}
    //              3. a[i] + dp[i - 1][2] {Stopped using it at previous element}

    // dp[i][1] =>  1. a[i]
    //              2. a[i] + dp[i - 1][1]

    // dp[i][2] =>  1. x * a[i]
    //              2. x * a[i] + dp[i - 1][1] {available, and wasnt being used}
    //              3. x * a[i] + dp[i - 1][2] {available, and was being used}
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        dp[i][0] = dp[i][1] = dp[i][2] = a[i];
        dp[i][2] *= x;
        if (i > 0) {
            dp[i][0] += max({0LL, dp[i - 1][0], dp[i - 1][2]});
            dp[i][1] += max({0LL, dp[i - 1][1]});
            dp[i][2] += max({0LL, dp[i - 1][1], dp[i - 1][2]});
        }
        ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
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
