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

const ll INF = 8e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    ll mini = INF;
    for (ll a = 0; a * a * a <= 2 * n; ++a) {
        ll L = 0, R = ll(1e6);
        --L, ++R;
        while (R > L + 1) {
            ll mid = L + (R - L) / 2;
            ll x = (a + mid) * (a * a + mid * mid);
            // a^3 + b^3 + a^2b + ab^2 = (a + b)(a^2 + b^2)
            if (x >= n) {
                mini = min(mini, x);
                R = mid;
            } else {
                L = mid;
            }
        }
    }
    cout << mini << '\n';
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
