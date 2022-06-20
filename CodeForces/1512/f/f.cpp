/**
 *    author:  master._.mind
 *    created: 2022.06.20 19:50:14
 **/

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
    ll n, c;
    auto Ceil = [](ll a, ll b) { return (a + b - 1) / b; };
    cin >> n >> c;
    vector<ll> a(n), b(n - 1);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    ll money = 0, min_days = INF;
    ll days_since = 0;
    // try to buy everyday, and move on next to repeat
    // find minimum for each day
    for (ll i = 0; i < n; ++i) {
        ll days_to_stay = days_since + Ceil(max(c - money, 0LL), a[i]);
        min_days = min(min_days, days_to_stay);
        if (i != n - 1) {
            ll days_to_move_on = Ceil(max(b[i] - money, 0LL), a[i]);
            money += (days_to_move_on * a[i] - b[i]);
            days_since += 1 + days_to_move_on;  // 1 day to move to next
        }
    }
    cout << min_days << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
