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
    ll a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    if (k1 > k2) swap(a1, a2), swap(k1, k2);
    ll mini = 0, maxi = 0;
    ll none = a1 * (k1 - 1) + a2 * (k2 - 1);
    if (n > none) {
        mini = min(n - none, a1 + a2);
    } else {
        mini = 0;
    }
    // a1 needs less cards
    ll temp = min(n / k1, a1);
    maxi += temp;
    n -= k1 * temp;
    temp = min(n / k2, a2);
    maxi += temp;
    cout << mini << ' ' << maxi << '\n';
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
