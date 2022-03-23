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
    auto bits = [](uint32_t n) {
        uint32_t cnt = 0;
        while (n) {
            n /= 2;
            ++cnt;
        }
        return cnt;
    };
    uint32_t n;
    cin >> n;
    ll ans = 0;
    while (n > 0) {
        uint32_t pop = bits(n), before = (1LL << (pop - 1));
        uint32_t far = (n - before);
        ans += far;
        n -= (far + 1);
    }
    cout << ans << '\n';
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
