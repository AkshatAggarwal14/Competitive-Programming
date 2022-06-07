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
    vector<ll> a(5);
    for (auto &it : a) cin >> it;
    vector<ll> vals;
    for (ll i = 0; i < 5; ++i) {
        for (ll j = i + 1; j < 5; ++j) {
            for (ll k = j + 1; k < 5; ++k) {
                vals.push_back(a[i] + a[j] + a[k]);
            }
        }
    }
    sort(all(vals));
    cout << vals[sz(vals) - 3] << '\n';
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
