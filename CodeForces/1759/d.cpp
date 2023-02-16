#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, m;
    cin >> n >> m;
    ll n0 = n;
    int cnt2 = 0, cnt5 = 0;
    ll mul = 1;
    while (n % 2 == 0) n /= 2, cnt2++;
    while (n % 5 == 0) n /= 5, cnt5++;
    while (cnt2 < cnt5 && mul * 2 <= m) cnt2++, mul *= 2;
    while (cnt5 < cnt2 && mul * 5 <= m) cnt5++, mul *= 5;
    while (mul * 10 <= m) mul *= 10;

    // largest multiple of mul <= m
    ll term = (m / mul) * mul;
    cout << n0 * term << '\n';
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
