#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
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
    ll n, u, d;
    cin >> n >> u >> d;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    ll pos = 1, c = 1;
    for (ll i = 1; i < n; ++i) {
        ll delta = a[i] - a[i - 1];
        if (delta >= 0) {
            if (delta <= u)
                ++pos;
            else
                break;
        } else {
            if (d >= -delta) {
                ++pos;
            } else {
                if (c > 0) {
                    --c;
                    ++pos;
                } else {
                    break;
                }
            }
        }
    }
    cout << pos << '\n';
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
