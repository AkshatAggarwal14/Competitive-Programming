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
    using ar3 = array<ll, 3>;
    ll n;
    cin >> n;
    vector<ar3> less, greater;
    for (ll i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        if (a < b)
            less.push_back({a, b, i});
        else
            greater.push_back({a, b, i});
    }
    sort(all(less), [](const ar3 &a, const ar3 &b) {
        return a[1] > b[1];
    });
    sort(all(greater), [](const ar3 &a, const ar3 &b) {
        return a[1] < b[1];
    });
    if (sz(less) > sz(greater)) swap(less, greater);
    cout << sz(greater) << '\n';
    for (auto &x : greater) cout << x[2] + 1 << ' ';
    cout << '\n';
    dbg(less, greater);
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
