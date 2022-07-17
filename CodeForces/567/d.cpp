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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    if (n < 3) return void(cout << "0\n");
    // lets fix middle element, thus we need count of a[i]/k, before element, and k * a[i] after element
    unordered_map<ll, ll> pre, suff;
    ll ans = 0;
    for (int i = 1; i < n; ++i) ++suff[a[i]];
    for (int i = 1; i < n; ++i) {
        ++pre[a[i - 1]];
        --suff[a[i]];
        if (a[i] % k == 0)
            ans += pre[a[i] / k] * suff[a[i] * k];
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
