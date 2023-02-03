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
    ll xr = 0;
    cin >> xr;
    bitset<30> a = xr, b;
    if (xr & 1) return void(cout << "-1\n");
    ll left = xr / 2;
    for (ll i = 29; i >= 0; --i) {
        ll val = (1 << i);
        if (val <= left) {
            if (a[i]) return void(cout << "-1\n");
            a[i] = 1;
            b[i] = 1;
            left -= val;
        }
    }
    ll A = a.to_ullong(), B = b.to_ullong();
    assert(A + B == 2 * xr && (A ^ B) == xr);
    cout << A << ' ' << B << '\n';
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
