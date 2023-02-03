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
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    set<pair<int, int>> unq;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int num = y - y0;
        int den = x - x0;
        if (den == 0) {
            num = 1;
        } else if (num == 0) {
            den = 1;
        } else {
            int g = __gcd(num, den);
            num /= g;
            den /= g;
        }
        unq.insert({num, den});
    }
    cout << unq.size() << "\n";
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
