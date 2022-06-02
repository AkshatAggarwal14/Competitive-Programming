/*
    Print LIS [Longest Increasing Subsequence] of an array
*/

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

const ll N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    auto b = a;
    sort(all(b));
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    vector<ll> LIS;
    ll x = n, y = n;
    while (dp[x][y]) {
        if (a[x - 1] == b[y - 1]) {  // if equal characters, we move diagonally left, and add char
            LIS.push_back(a[x - 1]);
            --x, --y;
        } else {
            if (dp[x - 1][y] >= dp[x][y - 1]) {  // else we move towards larger value in dp table
                --x;
            } else {
                --y;
            }
        }
    }
    reverse(all(LIS));
    for (auto &A : LIS) cout << A << ' ';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
