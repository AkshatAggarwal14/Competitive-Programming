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
    ll x, y;
    cin >> x >> y;
    ll z = x ^ y;
    ll a = 2, b = x ^ 2, c = z ^ 2;
    if (b % 2 == 0 || c % 2 == 0) {
        b = 2, a = x ^ 2, c = y ^ 2;
        if (a % 2 == 0 || c % 2 == 0) {
            c = 2, a = z ^ 2, b = y ^ 2;
        }
    }
    vector<ll> ans = {a, b, c};
    sort(all(ans));
    for (ll &i : ans) cout << i << ' ';
    cout << '\n';
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
