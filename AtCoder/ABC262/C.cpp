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
    ll ans = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    ll equal = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == i + 1) {
            ans += equal;
            ++equal;
        }
    }
    for (ll i = 0; i < n; ++i) {
        ll id = a[i] - 1;
        ll id2 = a[id] - 1;
        if (id2 == i && a[id] > a[id2] && id2 > id) ++ans;
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
