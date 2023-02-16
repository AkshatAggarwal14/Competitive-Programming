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
    ll n;
    cin >> n;
    if (n % 20 != 19) return void(cout << n / 2 << ' ' << (n + 1) / 2 << '\n');
    // x + y = n
    // only numbers of form 20n-1 left
    ll a = 0, b = 0, term = 1;
    while (n) {
        ll d = n % 10;
        n /= 10;
        ll half = d / 2;
        if (d & 1) {
            if (a < b) {
                a += term * (half + 1);
                b += term * half;
            } else {
                b += term * (half + 1);
                a += term * half;
            }
        } else {
            a += term * half;
            b += term * half;
        }
        term *= 10;
    }
    cout << a << ' ' << b << '\n';
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