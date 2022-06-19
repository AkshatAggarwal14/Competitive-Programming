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
    int n;
    cin >> n;
    ll ops = 0;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    ops += *min_element(all(a));
    for (auto &i : a) i -= ops;  // now all elements >= 0
    ops = abs(ops);
    auto fun = [&](vector<ll> &v) {
        auto pre = v;
        for (ll i = 1; i < n; ++i) pre[i] = min(pre[i - 1], pre[i]);
        dbg(pre);
        ops += pre[0];
        for (ll i = 0; i < n; ++i) v[i] -= pre[i];
    };
    dbg(a);
    fun(a);
    reverse(all(a));
    fun(a);
    reverse(all(a));
    dbg(ops, a);
    for (ll i = 1; i < n - 1; ++i) {
        ops += 2 * a[i];
    }
    cout << ops << '\n';
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
