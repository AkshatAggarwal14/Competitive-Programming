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
    ll a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    ll aoki = 0, taka = 0;
    ll y = x;
    while (x) {
        aoki += min(d, x) * e;
        x -= min((d + f), x);
    }
    while (y) {
        taka += min(a, y) * b;
        y -= min((a + c), y);
    }
    if (aoki == taka) return void(cout << "Draw");
    cout << ((taka > aoki) ? "Takahashi" : "Aoki");
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
