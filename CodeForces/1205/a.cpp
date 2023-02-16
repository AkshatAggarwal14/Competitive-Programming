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
    /**
     * Wrote brute, observed pattern in:
     * 1 4 5 8 9
     * 2 3 6 7 10
     */
    ll n;
    cin >> n;
    if (n % 2 == 0) return void(cout << "NO\n");
    n *= 2;
    vector<ll> a, b;
    for (ll i = 1; i <= n; i += 2) {
        if (a.empty()) {
            a.push_back(i);
            b.push_back(i + 1);
        } else if (a.back() < b.back()) {
            a.push_back(i + 1);
            b.push_back(i);
        } else {
            a.push_back(i);
            b.push_back(i + 1);
        }
    }
    cout << "YES\n";
    for (auto &x : a) cout << x << ' ';
    for (auto &x : b) cout << x << ' ';
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
