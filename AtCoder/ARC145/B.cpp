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
    ll n, a, b;
    cin >> n >> a >> b;
    if (n < a) return void(cout << "0\n");
    ll ans = 0;
    if (a > b) {
        ans += a - 1;                      // first a games won by 2nd player
        ans += (n / a - 1) * (a - b);      // last a - b games won by 2nd in remaining groups
        ans += max(0LL, n % a - (b - 1));  // leftover me a jeetega except first b - 1
    } else {
        ans = a - 1;
    }
    cout << n - ans << '\n';
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
