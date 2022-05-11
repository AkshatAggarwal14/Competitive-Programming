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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    sort(all(a), greater<ll>());
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    while (q--) {
        ll num;
        cin >> num;
        auto d = lower_bound(all(a), num) - a.begin() + 1;
        if (d > n) d = -1;
        cout << d << '\n';
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
