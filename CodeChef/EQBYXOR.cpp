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
    ll a, b, n;
    cin >> a >> b >> n;
    --n;
    if (a == b) return void(cout << "0\n");
    // 1 <= x <= 2^k
    ll val = (a ^ b);
    ll highest_bit_val = -1;
    for (ll i = 30; i >= 0; i--) {
        if (val & (1 << i)) {
            highest_bit_val = i;
            break;
        }
    }
    ll highest_bit_n = -1;
    for (ll i = 30; i >= 0; i--) {
        if (n & (1 << i)) {
            highest_bit_n = i;
            break;
        }
    }
    if (val <= n) return void(cout << "1\n");
    if (highest_bit_val > highest_bit_n) return void(cout << "-1\n");
    if (highest_bit_val == highest_bit_n) return void(cout << "2\n");
    cout << "1\n";
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
