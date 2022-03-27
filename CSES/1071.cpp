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
    ll y, x;
    cin >> y >> x;
    // y - even - dec - Y = (y - 1) ^ 2 + 1
    // y - odd - inc - Y = y ^ 2
    // x - even - inc - X = (x - 1) ^ 2 + 1
    // x - odd - dec - X = x ^ 2
    if (x >= y) {
        if (x & 1) {
            cout << x * x - (y - 1) << '\n';
        } else {
            cout << (x - 1) * (x - 1) + 1 + (y - 1) << '\n';
        }
    } else {
        if (y & 1) {
            cout << (y - 1) * (y - 1) + 1 + (x - 1) << '\n';
        } else {
            cout << y * y - (x - 1) << '\n';
        }
    }
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
