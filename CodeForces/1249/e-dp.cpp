#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

void Solution() {
    ll n, c;
    cin >> n >> c;
    vector<vector<ll>> dp(2, vector<ll>(n, LLONG_MAX));
    vector<ll> a(n - 1), b(n - 1);
    for (ll i = 0; i < n - 1; i++) cin >> a[i];
    for (ll i = 0; i < n - 1; i++) cin >> b[i];
    dp[0][0] = 0, dp[1][0] = c;  // elevators, overhead to start
    for (ll i = 1; i < n; ++i) {
        amin(dp[0][i], min(dp[1][i - 1], dp[0][i - 1]) + a[i - 1]);  // stairs - no overhead
        amin(dp[0][i], dp[0][i - 1] + a[i - 1]);                     // elevator to stair no overhead
        amin(dp[1][i], dp[1][i - 1] + b[i - 1]);                     // stay on elevator - no overhead
        amin(dp[1][i], dp[0][i - 1] + b[i - 1] + c);                 // stair to elevator = overhead
    }
    for (ll i = 0; i < n; ++i) cout << min(dp[0][i], dp[1][i]) << ' ';
    cout << '\n';
}

void smaller() {
    ll n, c;
    cin >> n >> c;
    vector<vector<ll>> dp(2, vector<ll>(n, LLONG_MAX));
    vector<ll> a(n - 1), b(n - 1);
    for (ll i = 0; i < n - 1; i++) cin >> a[i];
    for (ll i = 0; i < n - 1; i++) cin >> b[i];
    dp[0][0] = 0, dp[1][0] = c;
    for (ll i = 1; i < n; ++i) {
        dp[0][i] = a[i - 1] + min(dp[1][i - 1], dp[0][i - 1]);
        dp[1][i] = b[i - 1] + min(dp[1][i - 1], dp[0][i - 1] + c);
    }
    for (ll i = 0; i < n; ++i) cout << min(dp[0][i], dp[1][i]) << ' ';
    cout << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // ll tc; cin >> tc; while(tc--)
    smaller();
    return 0;
}
