#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll k = a * b;
    for (ll x = a + 1; x <= c; ++x) {
        // check if some y > b && y <= d, such that (x * y) % k == 0

        // xy / k is an integer
        // (x/g) * y / (k/g), such that now denominator completely divides y
        // y = z * (k/g)
        ll C = k / gcd(x, k);
        ll y = ((b + C) / C) * C;
        if (y <= d) return void(cout << x << ' ' << y << '\n');
    }
    cout << "-1 -1\n";
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
