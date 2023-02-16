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
    // [L + L+1 + L+2 + ... + L+n-1] = [1 + 2 + ... + 2n]
    // L = (3n+3)/2
    // Use 1 and 2n to make 2n+1, move left
    // cycle around then move left from right end
    if (n % 2 == 0) return void(cout << "No\n");
    ll L = (3 * n + 3) / 2, R = L + n - 1;
    cout << "Yes\n";
    for (ll i = 1; i <= n / 2 + 1; ++i) {
        cout << i << ' ' << 2 * n - 2 * (i - 1) << '\n';
    }
    for (ll i = n / 2 + 2; i <= n; ++i) {
        cout << i << ' ' << 2 * n - 1 - 2 * (i - (n / 2 + 2)) << '\n';
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
