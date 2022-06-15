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
    ll mini = INF;
    for (ll x = 1; x * x <= n; x++) {
        if (n % x != 0) continue;
        ll a = x, b = n - a;
        ll val = gcd(a, b) + lcm(a, b);
        if (val < mini) mini = val;
    }
    set<pair<ll, ll>> vals;
    for (ll x = 1; x * x <= n; x++) {
        if (n % x != 0) continue;
        ll a = x, b = n - a;
        if (gcd(a, b) + lcm(a, b) == mini && a > 0 && b > 0)
            vals.insert({a, b}), vals.insert({b, a});
        a = n / x, b = n - a;
        if (gcd(a, b) + lcm(a, b) == mini && a > 0 && b > 0)
            vals.insert({a, b}), vals.insert({b, a});
    }
    cout << sz(vals) << '\n';
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
