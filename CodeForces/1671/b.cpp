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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<ll> d;
    for (ll i = 1; i < n; ++i)
        if (a[i] - a[i - 1] > 1) d.push_back(a[i] - a[i - 1]);
    if (sz(d) == 0) return void(cout << "YES\n");
    if (sz(d) >= 3) return void(cout << "NO\n");
    if (sz(d) == 1) {
        if (d[0] <= 3) return void(cout << "YES\n");
    } else if (sz(d) == 2) {
        if (d[0] == 2 && d[1] == 2) return void(cout << "YES\n");
    }
    cout << "NO\n";
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
